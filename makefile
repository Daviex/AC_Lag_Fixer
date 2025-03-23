# Detect the platform
ifeq ($(OS),Windows_NT)
    PLATFORM := win
    RM := del /Q
    WSL := wsl
else
    PLATFORM := linux
    RM := rm -f
    WSL :=
endif

all: build_64 zip_64 build_linux_64 zip_linux_64

build_64:
	g++ -std=c++17 main.cpp -o ac_lag_fix_64_$(PLATFORM)

zip_64:
	zip ac_lag_fix_64_$(PLATFORM).zip ac_lag_fix_64_$(PLATFORM)

build_linux_64:
	$(WSL) g++ -std=c++17 main.cpp -o ac_lag_fix_64_$(PLATFORM)

zip_linux_64:
	$(WSL) zip ac_lag_fix_64_$(PLATFORM).zip ac_lag_fix_64_$(PLATFORM)

clean:
	$(RM) ac_lag_fix_64_$(PLATFORM) ac_lag_fix_64_$(PLATFORM).zip
	$(WSL) rm -f ac_lag_fix_64_$(PLATFORM) ac_lag_fix_64_$(PLATFORM).zip