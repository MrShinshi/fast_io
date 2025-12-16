const CACHE_NAME = "fast_io-docs-v4.1";
const urlsToCache = [
  "/",
  "/style.css",
  "/script.js",
  "/sw-register.js",
  "/manifest.json",
  "/icons/logo.webp",
  "/docs/intro/",
//  "/docs/api/",
  "/docs/01.io/",
  "/docs/01.io/01.helloworld/",
  "/docs/01.io/02.aplusb/",
  "/docs/01.io/03.pointer/",
  "/docs/01.io/04.fileio/",
  "/docs/01.io/05.filetypelayers/",
  "/docs/02.dsal/",
  "/docs/02.dsal/01.string/",
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
