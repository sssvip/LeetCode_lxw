#!/usr/bin/python2.7
# FileName: server.py
# Author: lxw
# Date: 2015-08-13

import socket

def main():
    server = socket.socket()
    host = socket.gethostname()
    port = 8080
    server.bind((host, port))
    server.listen(3)
    while 1:
        client, address = server.accept()
        client.send("welcome, {0}!".format(address[0]))
        client.send("Bye!")
        client.close()

if __name__ == '__main__':
    main()
else:
    print("Being imported as a module.")

