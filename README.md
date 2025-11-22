# Docker Compose 4every1

I've been toying with compose for so long and I think this might be useful for those who want 
to playaround.

## Current Services

- redis
- mongodb
- postgres
- hoppscotch All-In-One (including migration service bcz it won't run without migration)
- mailcatcher
- prometheus
- jaeger
- grafana
- kafdrop (web UI)
- kafka
- zookeeper
- memos (note taking web)
- n8n

## Easy Playaround

1. Build the `app/`
2. It will generate `main` binary at root project
3. `./main` will prompt the information
4. The stack name represent the directory (ex: `./main stack hoppscotch` will run hoppscotch compose)

List available stack:

- hoppscotch
- memos
- n8n
- databases
- eventstream
- monitoring
