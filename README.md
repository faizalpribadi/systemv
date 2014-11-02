systemv
=======

Create simply service daemon on systemd


Dependencies
============

* `Linux OS`

* `systemd already installed`


Installation
============

* `$ git clone https://github.com/faizalpribadi/systemv.git`

* `$ ./systemv`


Usage 
=====

* `copy files of {systemv.socket,systemv.service} to /etc/systemd/system`

* `systemctl enable systemv.socket`

* `systemctl start systemv.socket`

* `check systemv is already running & loaded with this command [ systemctl | grep systemv ]`
