ARG FROM_IMAGE=vnv_base
FROM ${FROM_IMAGE}

#Install the simple application example. 
COPY . ${SOURCE_DIR}/simple  
RUN  cd ${SOURCE_DIR}/simple \
     && mkdir build \
     && cd build \
     && cmake -DInjection_DIR=${VNV_DIR}/lib/cmake -DCMAKE_INSTALL_PREFIX=${SOFTWARE_DIR}/simple .. \
     && make \
     && make install  \
     && cp -r ../vnv/config ${SOFTWARE_DIR}/simple/gui \
     && rm -r ${SOURCE_DIR}/simple

RUN echo ${SOFTWARE_DIR}/simple/gui/vnv.__registration__  >> ${HOME}/.vnv

