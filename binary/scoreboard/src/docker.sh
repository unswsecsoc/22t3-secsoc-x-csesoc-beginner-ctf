docker build -t scoreboard .
docker run -d -p 9999:9999 --name=scoreboard scoreboard
