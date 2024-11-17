This branch is for scripts and specs for setting up code server adhoc asynchronous collaboration fully-managed through cloud vps or fully on-premise infrastrcution.

### Works so far
This setup is basic for team programming
- Password config
- One-time setup script
    - This also includes sed'ing files like Caddy
- Compose file
    - With proper variables through interpolation and fallbacks matching the .env file
    - `.env` file
- Caddy reverse proxy domains for LetsEncrypt HTTPS encryption

### Reached the goals
- Proper gitignore to ensure that bind mounts are not included when switching branches or rebases
- Centralized `share:/host_share` directory for deploying or syncing up-to-date files for all instances of the containers (e.g. multiple extension or script deployment)

### Quirks
When bidrectionally sharing each other's workspace, one would see an empty folder of their workspace inside other person's workspace... \
But should not affect the way how things are accessed either way

