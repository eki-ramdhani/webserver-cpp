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

Terdapat 2 jenis file HTML berukuran 500B dan 20KB pada folder `HTML Test` yang masing-masing akan diuji di dua webserver yang berbeda, Apache dan Nginx. Pengujian yang dilakukan akan menggunakan 10000 concurrent request

Berikut ini adalah hasil pengujian pada webserver : 

Untuk menguji  sebuah apache webserver dengan 10000 request dan concurrent level 1000, diberikanlah command dibawah ini : 

```
ab -n 10000 -c 1000 http://localhost:80/
```


##NGINX

###500B

Berikut ini adalah hasil pengujian dengan file html 500B : 

Requests per second:    14279.88 [#/sec] (mean)
Time per request:       70.029 [ms] (mean)
Time per request:       0.070 [ms] (mean, across all concurrent requests)
Transfer rate:          243554.12 [Kbytes/sec] received
Memory Usage: 0.1% (mean)

###20KB

Berikut ini adalah hasil pengujian dengan file html 20KB : 

Requests per second:    14605.73 [#/sec] (mean)
Time per request:       68.466 [ms] (mean)
Time per request:       0.068 [ms] (mean, across all concurrent requests)
Transfer rate:          264578.70 [Kbytes/sec] received
Memory Usage: 0.1% (mean)


##APACHE

###500B

Berikut ini adalah hasil pengujian dengan file html 500B : 

Requests per second:    3567.94 [#/sec] (mean)
Time per request:       280.274 [ms] (mean)
Time per request:       0.280 [ms] (mean, across all concurrent requests)
Transfer rate:          2682.93 [Kbytes/sec] received
Memory Usage: 0.1% (mean)


###20KB

Berikut ini adalah hasil pengujian dengan file html 20KB : 

Requests per second:    6901.06 [#/sec] (mean)
Time per request:       144.905 [ms] (mean)
Time per request:       0.145 [ms] (mean, across all concurrent requests)
Transfer rate:          136585.70 [Kbytes/sec] received
Memory Usage: 0.1% (mean)


