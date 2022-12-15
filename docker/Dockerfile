ARG FROM_IMAGE=vnv_base
FROM ${FROM_IMAGE}

ARG COMMIT_HASH=unknown
LABEL  vnv.version.simple=${COMMIT_HASH}


#Install the simple application example. 
COPY . ${SOURCE_DIR}/simple  
RUN  cd ${SOURCE_DIR}/simple \
     && mkdir build \
     && cd build \
     && cmake -DInjection_DIR=${VNV_DIR}/lib/cmake .. \
     && make 

ENV VNV_CONFIG=${VNV_CONFIG}:${SOURCE_DIR}/simple/build/vnv.__registration__

ENV VNV_CONFIG=${VNV_CONFIG}:${SOURCE_DIR}/simple/docker/config/vnv.__registration__
