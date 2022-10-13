docker build -t codecc .
docker run -d -p 9999:9999 --name=codecc -e container=docker --privileged codecc
