
[ -z "$AWS_DEFAULT_REGION" ] && export AWS_DEFAULT_REGION=us-east-1

function s3_test_connection() {

    case $S3_BACKEND in
    awscli)     aws s3 ls "$S3PATH"
                case $? in
                0)      return 0 ;; # all good
                1)      return 0 ;; # can't list but good
                *)      return 1 ;; # weird error
                esac
                ;;
    s3cmd)      $S3CMD $S3CMD_OPTIONS ls "$S3PATH" || return 1  ;;
    esac

}

function s3_list_files_raw () {

    case $S3_BACKEND in
    awscli)     aws s3 ls "$S3PATH/"  ;;
    s3cmd)      $S3CMD $S3CMD_OPTIONS ls "$S3PATH"/  ;;
    esac

}

function s3_list_files () {

    case $S3_BACKEND in
    awscli)     aws s3 ls "$S3PATH/" | awk '{print $4}' | grep -P '^\d{8}\.\d\d\.tgz(\.lst)?' ;;
    s3cmd)      $S3CMD $S3CMD_OPTIONS ls "$S3PATH"/ |  grep "$S3PATH" | sed "s@.*$S3PATH/@@" | grep -e 'tgz.lst' -e 'tgz$' ;;
    esac

}

function s3_put_file() {

    echo == ${FUNCNAME[0]} $@
    case $S3_BACKEND in
    awscli)     aws s3 cp "$1" "$2"  ;;
    s3cmd)       $S3CMD $S3CMD_OPTIONS put "$1" "$2"  ;;
    esac

}


function s3_rm_file() {

    case $S3_BACKEND in
    awscli)     aws s3 rm "$1" ;;
    s3cmd)      $S3CMD $S3CMD_OPTIONS rm "$1" ;;
    esac

}


function s3_sync_dir() {

    echo "== s3_sync_dir $DESTDIR $S3PATH"
    case $S3_BACKEND in
    awscli)     aws s3 sync --exclude '*' --include '*tgz' --include '*tgz.lst' --include '*dar' $DESTDIR $S3PATH ;;
    s3cmd)      $S3CMD $S3CMD_OPTIONS -v  --exclude '*'  --include='*tgz' --include='*tgz.lst' --include='*dar'   sync  $DESTDIR/ $S3PATH/  ;;
    esac

}


# vim: filetype=sh

