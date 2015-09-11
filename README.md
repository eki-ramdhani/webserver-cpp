#Benchmark

Tools yang digunakan pada benchmarking web server adalah ApacheBench. Cara melakukan test adalah sebagai berikut (Testing dilakukan pada OS Ubuntu 14.04) : 

----------

 1.  Refresh list package di komputer anda dengan 
```
sudo apt-get update
```
 2. Lakukan instalasi apache2-utils untuk dapat menggunakan ApacheBench
```
 apt-get install apache2-utils
```
 3. Untuk melakukan pengujian, jalankan : 
```
ab -n <num_requests> -c <concurrency> <addr>:<port><path>
```
