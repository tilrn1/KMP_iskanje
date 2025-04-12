FROM ubuntu:latest
WORKDIR /app
COPY . /app
RUN g++ -o KMP Vaja2_KMP.cpp
CMD ["./Vaja2.exe", "0 'Lorem ipsum' test.txt"]