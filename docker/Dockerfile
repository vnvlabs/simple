ARG FROM_IMAGE=vnv_base
FROM ${FROM_IMAGE}:latest

#Install the simple application example. 
COPY . ./simple  
RUN  cd simple && mkdir build && cd build && cmake -DInjection_DIR=${VNV_DIR}/lib/cmake .. && make 

ARG COMMIT_HASH=unknown
LABEL  vnv.version.simple=${COMMIT_HASH}

ENV VNV_CONFIG=${VNV_CONFIG}:/simple/.vnv-config.json

