/**
  Copyright 2014 Faizal Pribadi

  Permission is hereby granted, free of charge, to any person
  obtaining a copy of this software and associated documentation files
  (the "Software"), to deal in the Software without restriction,
  including without limitation the rights to use, copy, modify, merge,
  publish, distribute, sublicense, and/or sell copies of the Software,
  and to permit persons to whom the Software is furnished to do so,
  subject to the following conditions:

  The above copyright notice and this permission notice shall be
  included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
  ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
***/

/**
 * Expose main headers
 */
#include "sys/socket.h"
#include "sys/un.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/**
 *Expose source headers
 */
#include "../libs/systemd/sd-daemon.h"
#include "systemv.h"

/**
 * Bind structure from 'sys/socket' & 'sys/un'
 */
union {
	struct sockaddr sa;
	struct sockaddr_un un;
} sa;

/**
 * Global variables
 */
static int fd, n;

/**
 *
 */
int main() {
	/**
	 *
	 */
	n = sd_listen_fds(0);
	if (n > 1) {
		fprintf(stderr, "Too many file descriptors received.\n");
		exit(1);
	} else if (n == 1) {
		fd = SD_LISTEN_FDS_START + 0;
	}

	/**
	 * Create & bind socket
	 */
	fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if (fd < 0) {
		fprintf(stderr, "socket(): %m\n");
		exit(1);
	}

	/**
	 * Set the name of daemon service called is 'systemv'
	 */
	memset(&sa, 0, sizeof(sa));
	sa.un.sun_family = AF_UNIX;
	strncpy(sa.un.sun_path, "/var/run/systemv.sk", sizeof(sa.un.sun_path));

	/**
	 * If already bind the socket of systemv
	 */
	if (bind(fd, &sa.sa, sizeof(sa)) < 0) {
			fprintf(stderr, "bind(): %m\n");
			exit(1);
	}

	/**
	 * Bind()
	 */
	if (listen(fd, SOMAXCONN) < 0) {
			fprintf(stderr, "listen(): %m\n");
			exit(1);
	}
}



