docker build -t echo .
docker run -d -p 9999:9999 --name=echo echo
