all: directory build_64 zip_64 build_linux_64 zip_linux_64

directory:
    mkdir -p output

build_64: directory
    g++ -std=c++17 main.cpp -o output/ac_lag_fix_win_x64

zip_64: build_64
    zip output/ac_lag_fix_win_x64.zip output/ac_lag_fix_win_x64

build_linux_64: directory
    wsl g++ -std=c++17 main.cpp -o output/ac_lag_fix_linux_x64

zip_linux_64: build_linux_64
    wsl zip output/ac_lag_fix_linux_x64.zip output/ac_lag_fix_linux_x64

clean:
    $(RM) -r output