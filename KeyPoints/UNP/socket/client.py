#!/usr/bin/python2.7
# FileName: client.py
# Author: lxw
# Date: 2015-08-13

import socket

def main():
    client = socket.socket()
    #Both of the following 2 method are OK:
    #host = socket.gethostbyname(socket.gethostname())   #127.0.0.1
    host = socket.gethostname() #ubuntu

    #print(type(host))   #str

    #host = '192.168.137.132' #no
    #host = '127.0.0.1'     #no
    port = 8080
    client.connect((host, port))
    content = client.recv(1024)
    print(content)
    client.close()


if __name__ == '__main__':
    main()
else:
    print("Being imported as a module.")

