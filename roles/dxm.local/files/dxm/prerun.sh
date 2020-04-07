#!/bin/bash

PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

########### fix_bad_views START
#
#
#. /etc/dxm/dxm.conf
#
#if [[ $DOMYSQL == 1 ]]; then
#
#IFS=$'\n'
#
#list_views() {
#mysql  -se 'select definer,TABLE_SCHEMA,md5(VIEW_DEFINITION) as view from  information_schema.views where  TABLE_schema!="sys" ;' | cat 
#}
#
#for line in $( list_views ); do
#    definer=$(echo $line| awk '{print $1}')
#    db=$(echo $line| awk '{print $2}')
#    view_md5=$(echo $line| awk '{print $3}')
#    if [[ `echo $definer | cut -d@ -f1` != $db ]]
#    then    echo "-- bad view $line"
#            echo 'SELECT CONCAT("ALTER DEFINER=`'$db'`@localhost VIEW `", table_schema, "`.`", table_name, "` AS ", view_definition, ";") FROM information_schema.views WHERE md5(VIEW_DEFINITION)="'$view_md5'" and  table_schema="'$db'" ;'  | mysql -s 
#    fi
#done | tee  /tmp/fix_views.$$
#cat /tmp/fix_views.$$
#mysql <  /tmp/fix_views.$$
#rm /tmp/fix_views.$$
#
#fi
#
########### fix_bad_views end

exit 0

