const CACHE_NAME = "fast_io-docs-v3";
const urlsToCache = [
  "/",
  "/style.css",
  "/script.js",
  "/sw-register.js",
  "/manifest.json",
  "/icons/logo.webp",
  "/docs/intro/",
//  "/docs/api/",
  "/docs/01.helloworld/",
  "/docs/02.aplusb/",
  "/docs/03.pointer/",
  "/docs/04.fileio/",
  "/docs/05.filetypelayers/",
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
