FROM mcr.microsoft.com/vscode/devcontainers/base:ubuntu

RUN apt-get update && apt-get install -y --no-install-recommends \
    xauth \
    libxext-dev \
    libbsd-dev \
    valgrind \
    && rm -rf /var/lib/apt/lists/*

