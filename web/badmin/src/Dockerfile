FROM node:16-alpine

RUN mkdir /app
WORKDIR /app

COPY package.json package-lock.json ./
RUN npm install

COPY index.js ./
COPY static ./static

EXPOSE 8000

CMD ["node", "."]
