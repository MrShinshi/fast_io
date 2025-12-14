const CACHE_NAME = "fast_io-docs-v1";
const urlsToCache = [
  "/",
  "/style.css",
  "/script.js",
  "/sw-register.js",
  "/manifest.json",
  "/icons/logo.webp",
  "/docs/intro.html",
  "/docs/api.html",
  "/docs/01.helloworld.html",
  "/docs/02.aplusb.html",
  "/docs/03.pointer.html",
  "/docs/04.fileio.html",
  "/docs/05.filetypelayers.html",
];

self.addEventListener("install", event => {
  event.waitUntil(
    caches.open(CACHE_NAME).then(cache => cache.addAll(urlsToCache))
  );
});

self.addEventListener("fetch", event => {
  event.respondWith(
    caches.match(event.request).then(response => response || fetch(event.request))
  );
});
