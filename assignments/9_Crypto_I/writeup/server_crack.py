#!/usr/bin/env python3

import hashlib
import string
import socket
import time

def server_crack():
    hashes = open("hashes.txt", "r") # open and read hashes.txt
    passwords = open("passwords.txt", "r") # open and read passwords.txt
    characters = string.ascii_lowercase
    server_ip = '134.209.128.58'
    server_port = 1337

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((server_ip, server_port))

    for i in range(3):
        time.sleep(1)
        data = s.recv(1024)
        input = data.splitlines()
        hash = str(input[2], 'utf-8')
        print(hash)
        for p in passwords:
            input = p.rstrip()
            for c in characters:
                test_input = c + input
                test_hash = hashlib.sha256(test_input.encode()).hexdigest()
                if test_hash == hash:
                    print("It's a match!")
                    s.send(test_input.encode())
                    time.sleep(1)

if __name__ == "__main__":
    server_crack()
