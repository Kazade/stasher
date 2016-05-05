# Stasher

Stasher is an in-memory reimplementation of the Google App Engine datastore. It is written in C++ and is designed as a replacement datastore stub when running unit tests. The project aims are:

 - To massively outperform the SQLite stub by not serializing to protobufs
 - To provide a Python API for monkey-patching the Python GAE testbed 
 - To use an architecture that will allow for persistent storage in future
