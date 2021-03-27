#!/usr/bin/perl
#
# /var/www/html/form.pl
#
# In order to run this script on Centos7 from /var/www/html, install
# the perl-CGI package. Also, add the following statements into
# /etc/httpd/conf/httpd.conf section <Directory "/var/www/html">:
#
# Options +ExecCGI
# AddHandler cgi-script .pl
#

use CGI;

$query = new CGI;

$timestamp = scalar(localtime());
@values = $query->param('id');

print $query->header('text/plain');

print "Script executed at: $timestamp\n\n";

print "Value(s) for id parameter:\n";
print join("\n", @values);