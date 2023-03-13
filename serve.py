#!/usr/bin/env python3
"""
License: MIT License
Copyright (c) 2023 Miel Donkers
Very simple HTTP server in python for logging requests
Usage::
    ./server.py [<port>]
"""
from http.server import SimpleHTTPRequestHandler, HTTPServer
import logging
import subprocess

class S(SimpleHTTPRequestHandler):
    def _set_response(self):
        return super().baz()

    def do_GET(self):
        if self.path[-1] == '/' :
            runNinjaCmd = "ninja"
            p = subprocess.Popen(runNinjaCmd, stdout=subprocess.PIPE, shell=True)
            (output, err) = p.communicate()  
            outputStr = str(output)
            outputStr.replace('\0', '\n')
            outputStr.replace('\b', '\n')
            print("Ninja ran\nOutput: " + outputStr);
            
            if "error" in outputStr:
                self.send_response(200)
                self.end_headers()
                self.wfile.write(bytes(outputStr, 'utf-8'))
                return
                
        return super().do_GET()

    def do_POST(self):
        return super().do_POST()

def run(server_class=HTTPServer, handler_class=S, port=8000):
    logging.basicConfig(level=logging.INFO)
    server_address = ('', port)
    httpd = server_class(server_address, handler_class)
    logging.info('Starting httpd...\n')
    try:
        httpd.serve_forever()
    except KeyboardInterrupt:
        pass
    httpd.server_close()
    logging.info('Stopping httpd...\n')

if __name__ == '__main__':
    from sys import argv

    if len(argv) == 2:
        run(port=int(argv[1]))
    else:
        run()