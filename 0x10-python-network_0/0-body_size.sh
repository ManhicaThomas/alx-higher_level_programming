#!/bin/bash
# Script that takes in a url, sends a request and displays the size of the body of the response
curl -sI "$1" | grep "Content-Length" | cut -d " " -f2
