ARG USER="docker"
ARG DIR="/app"

FROM alpine:latest as base

ARG USER
ARG DIR

RUN set -euxo pipefail; \
  apk upgrade \
    --no-cache \
    --update \
  ; \
  apk add \
    --no-cache \
    --update \
      bash \
      tini \
      gcc \
      g++ \
  ;

WORKDIR $DIR
RUN set -euxo pipefail; \
  adduser \
    --disabled-password \
    --gecos "" \
    --home $(pwd) \
    --no-create-home \
    --uid 10000 \
      $USER \
  ; \
  chown $USER:$USER $DIR

USER $USER:$USER

FROM base as install

ARG USER
ARG DIR


COPY --chown=$USER:$USER main.cpp $DIR/

RUN set -euxo pipefail; \
  g++ main.cpp

FROM install as build

ARG USER
ARG DIR

COPY --chown=$USER:$USER . $DIR/

FROM base as run

EXPOSE 3000

COPY --from=build --chown=$USER:$USER $DIR/a.out $DIR/a.out

CMD [ "./a.out"]
