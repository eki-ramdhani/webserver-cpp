#include <sys/types.h>
#include <sys/time.h>
#include <sys/queue.h>
#include <stdlib.h>
#include <err.h>
#include <event.h>
#include <evhttp.h>
#include <fstream>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;

typedef struct {
  int port;
  string folder;
} config;

int getPort() {
  ifstream fs("config");
  config ret;
  fs >> ret.port;
  fs >> ret.folder;
  return ret.port;
}

string getFolder() {
  ifstream fs("config");
  config ret;
  fs >> ret.port;
  fs >> ret.folder;
  return ret.folder;
}

void generic_handler(struct evhttp_request *req, void *arg) {
    struct evbuffer *buf;
    string s = req->uri;
    if (s[s.length()-1] == '/') {
      s+="index.html";
    }
    struct stat st;
    buf = evbuffer_new();
    int fd = -1;
    string folder = getFolder();
    if ((fd = open((folder + s).c_str(), O_RDONLY)) < 0) {
      evhttp_send_error(req, 404, "Not found");
    }

    if (fstat(fd, &st)<0) {
      /* Make sure the length still matches, now that we
       * opened the file :/ */
      evhttp_send_error(req, 404, "Not found");
    }

    if (buf == NULL)
        err(1, "failed to create response buffer");
    evbuffer_add_file(buf, fd, 0, st.st_size);
    evhttp_send_reply(req, HTTP_OK, "OK", buf);
    cout << fd << endl;
    evbuffer_free(buf);
}

int main(int argc, char **argv) {
  struct evhttp *httpd;
  event_init();
  
  int port = getPort();
  
  httpd = evhttp_start("127.0.0.1", port);
  // cout << conf.folder << endl;
  /* Set a callback for requests to "/specific". */
  /* evhttp_set_cb(httpd, "/specific", another_handler, NULL); */

  /* Set a callback for all other requests. */
  evhttp_set_gencb(httpd, generic_handler, NULL);

  event_dispatch();    /* Not reached in this code as it is now. */
  evhttp_free(httpd);
    
  return 0;
}
