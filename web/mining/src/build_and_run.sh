#!/bin/bash
docker build -t miner .
docker run --rm -p 80:80 miner
