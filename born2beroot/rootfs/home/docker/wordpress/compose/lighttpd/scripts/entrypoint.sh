#!/bin/sh

mkdir -p /var/log/lighttpd 
chown -R lighttpd:lighttpd /var/log/lighttpd

touch /var/www/html/index.php

exec /usr/sbin/lighttpd -D -f /etc/lighttpd/lighttpd.conf