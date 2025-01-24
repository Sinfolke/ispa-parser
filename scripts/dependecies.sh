# script to download required dependecies
skip_spaces_poth() {
    # ARGS
    local str=$1
    local pos=$2
    local ret=$3

    for i in $(seq $pos $((${#str} - 1))); do
        if [[ $i != " " ]]; then
            ret=$i
            return true
        fi
    done
    ret=-1
    return false
}
parseStr() {
    #ARGS
    local str=$1
    local pos=$2
    local ret=$3

    local escaptions=0
    local str_end=-1
    local c=0
    for i in $(seq $begin $((${#str} - 1)));
    do
        c="${str:$i:1}"
        if [[ $c == "\\" ]]; then
            ((escaptions++))
            continue
        elif [[ $c == "\"" && $escaptions == 0 || $((escaptions % 2)) == 0 ]]; then
            # all escaptions are even so a close quote found
            $ret=$i
            return true
        fi
    done
    $ret=-1
    return false
}
get_include_options() {
    declare -A include_options

    local flags="$CFLAGS $CXXFLAGS"
    local begin=0
    for i in $(seq 0 $((${#flags} - 1)));
    do
        local c="${flags:$i:1}"
        if [[ $c == "\"" ]]; then
            # parse the string and jump to the end
            parseStr $flags $i $str_end
            ((i+=$str_end))
            continue
        fi 

        while [[ $c == " " ]]; do
            # begin of an argument
            begin=1
            # mov to the next character
            ((i++))
            c="${flags:$i:1}"
        done
           
        if [[ $begin && "$c" == "-" ]]; then
            # found flag
            i=$(( $i+1 ))
            c="${flags:$i:1}"
            if [[ "$c" == "I" ]]; then
                # -I 
                i=$(( $i+1 ))
                c="${flags:$i:1}"
                # get new position where no spaces
                skip_spaces_poth "$flags" $i i
                c="${flags:$i:1}"
                if [[ $c == "\"" ]]; then
                    # parse string
                    parseStr $flags $((i + 1)) str_end
                    if $str_end != 0; then
                        # failed to parse string
                        echo "Warning: your options in CC/CXX are invalid"
                        # quit till next argument
                        begin=0
                        continue
                    fi
                else
                    # parse until next space
                    skip_spaces_poth ${flags} $i str_end
                fi

                # capture string
                include_options += ${ flags:$(( i + 1 )):str_end }
                # move i to the end
                i=$str_end
            fi
        fi

        begin=0
    done
}