#!/usr/bin/env bash
set -e -u

# Ensure we cd into directory full path where this script is located
cd "$(dirname "$(readlink -f "$0")")"

# Copy the .env.template file to .env
echo "[*] Copying .env.template to .env"
cp .env.template .env

# Ask if the user wants to edit the .env file
read -p "Do you want to edit the .env file? [y/n] " -n 1 -r
echo ""

[[ $REPLY =~ ^[Yy]$ ]] && ${EDITOR:-vi} .env

# Perform sed the Caddyfile to change $USER1_NAME and $USER2_NAME from staging1 and staging2
if [ -f Caddyfile ]; then
    echo "[*] Setting up Caddyfile..."
    sed -i \
    -e "s/staging1/${USER1_NAME:-staging1}/g" \
    -e "s/staging2/${USER2_NAME:-staging2}/g" \
    Caddyfile
fi

# Autopopulate directories
echo "[*] Creating per user code-serverconfig directories..."
mkdir -p "config-${USER1_NAME:-staging1}"
mkdir -p "config-${USER2_NAME:-staging2}"

read -p "Also setup blank workspace directories? [y/n] " -n 1 -r
echo ""

# using the current shell context.
[[ $REPLY =~ ^[Yy]$ ]] && {
    echo "[*] Creating per user code-server workspace directories..."
    mkdir -p "workspace-${USER1_NAME:-staging1}"
    mkdir -p "workspace-${USER2_NAME:-staging2}"
}

echo "[*] Done! Please run 'docker compose up'"
