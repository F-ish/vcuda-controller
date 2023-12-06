#!/bin/bash
set -o errexit
set -o pipefail
set -o nounset
set -o xtrace

ROOT=$(cd $(dirname ${BASH_SOURCE[0]}) && pwd -P)
IMAGE_FILE=${IMAGE_FILE:-"fish/vcuda:old"}
FILEPATH=$PWD
img="unishare-ctl"
version="1.0.0"
repo="g-ubjg5602-docker.pkg.coding.net/iscas-system/containers"

function cleanup() {
    rm -rf ${ROOT}/cuda-control.tar
}

trap cleanup EXIT SIGTERM SIGINT

function build_img() {
    readonly local commit=$(git log --oneline | wc -l | sed -e 's,^[ \t]*,,')
    #readonly local version=$(<"${ROOT}/VERSION")

    rm -rf ${ROOT}/build
    mkdir ${ROOT}/build
    git archive -o ${ROOT}/build/cuda-control.tar --format=tar --prefix=cuda-control/ HEAD
    cp ${ROOT}/vcuda.spec ${ROOT}/build
    cp ${ROOT}/Dockerfile ${ROOT}/build
    (
      cd ${ROOT}/build
      #docker buildx create --name mybuilder --driver docker-container
      #docker buildx use mybuilder --node mybuilder
      #docker run --privileged --rm tonistiigi/binfmt --install all
      #docker run --rm --privileged multiarch/qemu-user-static --reset -p yes
      #docker build ${BUILD_FLAGS:-} --build-arg version=${version} --build-arg commit=${commit} -t ${IMAGE_FILE} .
      #docker buildx build $FILEPATH/build --platform linux/arm64,linux/amd64 --no-cache ${BUILD_FLAGS:-} --build-arg version=${version} --build-arg commit=${commit} -t $repo/$img:v$version --push  -f $FILEPATH/build/Dockerfile
      docker buildx build --load --no-cache /home/onceas/wyy/gpudeploy/vcuda-controller/build    --platform linux/amd64 ${BUILD_FLAGS:-} --build-arg version=${version} --build-arg commit=${commit} -t ${IMAGE_FILE}  -f /home/onceas/wyy/gpudeploy/vcuda-controller/build/Dockerfile
    )
}

build_img