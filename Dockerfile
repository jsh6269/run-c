FROM gcc:latest

WORKDIR /app

COPY . .

RUN g++ -o main main.cpp helper.cpp

CMD ["./main"]
