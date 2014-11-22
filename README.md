SYSTEMV
=======

Create simply service daemon on systemd


What's is Systemd ?
===================

`systemd` is a system and service manager for Linux, compatible with SysV and LSB init scripts. `systemd` provides aggressive parallelization capabilities, uses socket and D-Bus activation for starting services, offers on-demand starting of daemons, keeps track of processes using Linux control groups, supports snapshotting and restoring of the system state, maintains mount and automount points and implements an elaborate transactional dependency-based service control logic. It can work as a drop-in replacement for sysvinit


Dependencies Requirements
=========================

* `Linux OS 64-bit`

* `systemd libraries is already installed`


Installation
============

* `$ git clone https://github.com/faizalpribadi/systemv.git`

* `$ cd systemv && ./configure`


Usage 
=====

* `copy files of {systemv.socket,systemv.service} to /etc/systemd/system`

* `systemctl enable systemv.socket`

* `systemctl start systemv.socket`

* `check systemv is already running & loaded with this command [systemctl | grep systemv]`
