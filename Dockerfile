FROM gcc:15

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    cmake \
    ninja-build \
    gdb \
    make \
    doxygen \
    graphviz \
    pkg-config && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

CMD ["bash"]
