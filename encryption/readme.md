# OpenSSL in C++

## Installation
For Linux Ubuntu:
```
sudo apt-get install libssl-dev
```

For Windows:
```
# install scoop - windows package manager
Set-ExecutionPolicy RemoteSigned -Scope CurrentUser # Optional: Needed to run a remote script the first time
irm get.scoop.sh | iex

# install openssl
scoop install openssl
```

For macOS:
```
brew install openssl
```

## Run
```
cmake -S . -B build
cmake --build build
```