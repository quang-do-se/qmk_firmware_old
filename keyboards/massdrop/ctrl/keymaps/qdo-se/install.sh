#!/usr/bin/env bash

BASEDIR=$(cd -- "$(dirname -- "$0")" && pwd - P)

qmk compile -kb massdrop/ctrl -km qdo-se && \
"$BASEDIR/mdloader_linux" --first --download ../../../../../.build/massdrop_ctrl_qdo-se.bin --restart
