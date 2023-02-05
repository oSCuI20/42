FROM debian:bullseye-slim 

ENV DEBIAN_FRONTEND=noninteractive

RUN set -x && \
	apt-get update -y && \
	apt-get install -y lighttpd && \
	rm -Rf /var/cache/apk

RUN rm -Rf /etc/lighttpd/* /etc/logrotate.d/lighttpd /var/www/localhost && mkdir -p /var/www/html

RUN groupadd lighttpd
RUN useradd -g lighttpd -s /sbin/nologin -d /var/www/html lighttpd

COPY ./compose/lighttpd/conf/ /etc/lighttpd/
COPY ./compose/lighttpd/scripts/entrypoint.sh /start.sh

RUN chmod +x /start.sh 

EXPOSE 80/tcp

ENTRYPOINT ["/start.sh"]
#CMD ["-D", "-f", "/etc/lighttpd/lighttpd.conf"]