docker build -t dbdb .
docker run -d -p 9999:9999 --name=dbdb dbdb
