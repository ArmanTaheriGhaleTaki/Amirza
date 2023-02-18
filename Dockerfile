FROM gcc
COPY ["main.cpp","levels.txt","user.txt","/app/"]  
WORKDIR /app
RUN gcc *.cpp -lstdc++
ENTRYPOINT ["./a.out"] 
