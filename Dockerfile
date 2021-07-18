from archlinux/archlinux:base-devel
COPY . /app
run pacman -Syu --needed cmake make libsodium fish neofetch --noconfirm
run chsh -s /bin/fish
run cd /app && cmake . && make