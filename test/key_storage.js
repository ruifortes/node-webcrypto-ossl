var assert = require('assert');
var fs = require('fs');
var webcrypto = require('./config');

describe("Key storage", function () {

    var TEST_MESSAGE = new Buffer("This is test message for crypto functions");

    before(function (done) {
        done();
    })

    it("Set/get key from storage", function (done) {
        var key = null;
        webcrypto.subtle.generateKey({
            name: "RSASSA-PKCS1-v1_5",
            modulusLength: 1024,
            publicExponent: new Uint8Array([1, 0, 1]),
            hash: {
                name: "SHA-1"
            },
        },
            true,
            ["sign", "verify"]
        )
            .then(function (keyPair) {
                webcrypto.keyStorage.setItem("my_key", keyPair.privateKey);
                var exists = fs.existsSync(webcrypto.keyStorage.directory + "/my_key.json");
                assert.equal(exists, true, "File with key is not created");

                var storeKey = webcrypto.keyStorage.getItem("my_key");
                return Promise.resolve();
            })
            .then(done, done);
    });
    
    it("Clear key storage", function () {
        webcrypto.keyStorage.clear();
        assert.equal(webcrypto.keyStorage.length, 0);
    });
});