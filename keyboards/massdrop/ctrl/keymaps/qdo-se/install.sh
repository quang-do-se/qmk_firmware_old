#!/usr/bin/env bash

BASEDIR=$(cd -- "$(dirname -- "$0")" && pwd - P)

qmk compile && \
"$BASEDIR/mdloader_linux" --first --download ../../../../../.build/massdrop_ctrl_qdo-se.bin --restart
