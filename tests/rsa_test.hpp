#pragma once
#include <eosio/crypto.hpp>
#include <eosio/tester.hpp>

#include <ck/rsa.hpp>
#include <ck/utils.hpp>

#include "utils.hpp"

namespace ck::test {

    EOSIO_TEST_BEGIN(rsa_pkcs_1_5_sha256_test)
        // NIST FIPS 186-4 test vectors
        // https://csrc.nist.gov/projects/cryptographic-algorithm-validation-program/digital-signatures
        // CAVS 11.0
        // "SigVer PKCS#1 Ver 1.5" information
        // Combinations selected: Mod Size 1024 with SHA-256; Mod Size 2048 with SHA-256 ; Mod Size 3072 with SHA-256

        //[mod = 1024]
        auto n = "8592b5850b9ba96e7faecbdd67e50ed5fb2018fda0bc6a09ab6345910fc445ac6bdb0e7a4c6b72c9441649c9e78109bbaa1d79f9fafb8794a1a06cb638bd8f3c3416d44c43cf862b8ac1d5006310b05a7760d341d07077ae775f1695061d3c7297dd3ab8fc5d03d09ed1602a1bb69891bb377fd0aad6cd90f8b207467db36279"_hex;
        auto e = "eef211"_hex;
        auto m = "23d29062797ec367d664542872324b63a72305caed23d04b0834b594801095d7521078cae54c21f33f04e622793fbe3f70b19c45bee2fb8fe98dba53d9462b6c9060675c150ee491b1c849e75ef1806f7db60d6fc7399fa986efe5e00546a399458c051ff10c33c9947a257f0a91b97b35fa034df170e4224922de45eb5826e6"_hex;
        auto s = "02d07177f91c0db0b74e34b532aa18673d27fdee370b7aa9094ef765c9a8278b7128f1bd24fd3992e6376f83bdea9e505be10de15163286a7c9d9873bdbcffe0535f9f8cb0dd99ba34e24ec462e4ad03618258b66894daeac9415545e030bd963f2beb8d089183ec7ff1be67e6f94e6871d42fb7d7c694682a9f4af599bfdf81"_hex;
        auto r = false; // Result = F
        auto d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA-256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA-256 signature verification failed"
            );
        })

        e = "eef211"_hex;
        m = "1e422f898ff258a99bc53648541709b3a3bba5828d36d070b42bec6a2117d6e6403f0d762ce6179d2dc220e180b1e52156a9d0291eed64840787dc91c1f20fda841797a0547b32bb83b668a177276fc4aee64b21fefa391522cc4e7372dc5cd5f2b3152f8e1973aaa48757afc3df7041b35b5e91b5c317cc0be48a38bb3d837f"_hex;
        s = "2e37c8221597f7e2b1970c40a50db5fefde31b1dff1e9b9d6a70b023acb014971580eddf1d67f15d9fbbddfcdf49cda14ccb7516c33b787a3a3fd43d005d02de10f93ffc99585ae5dfaa766c0f1f5bfa62e50e76a059a4a1e814c1ee9836e01595731dce48f94aa1ae36d9c5165a3eb28013fac271e091f7018fe96ec26009c1"_hex;
        r = true; // Result = P
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s, "Failed verifying valid RSA PKCS1.5 SHA256 signature" );

        e = "eef211"_hex;
        m = "084e3b56d68ea7c99068489e2c8080b9d3eb5ffea1e67eaea9c82af33935c5b960956ac0aec4d0ef3b0b71ecea50ebe9ef89a6c18f77b743279004cd703da91e01459b6516898b9d8ff30e1d3ca9fa6b5786135252cae734d410f6a1fe811627f248166c9645a27b9506665ca7f377e713c8eed97249d628b5314894696bd47f"_hex;
        s = "1b7dfda3e6da9e67ee9f207a9e03559fb5d7ec88f0310ac051e1e0612119214bcb11d1003bb5fbea088354c2a9c3318baa0264f67f0860f17528bfa63ee35f22908caf0e8e57c0ce63b334b747cc1a31ff90cdd550b27a34b05695a39d48e900a5e1ab4ce3f5030d903315a5dadbdbb0ffae04134a74cde2b99b8f8b5305759c"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "990d05"_hex;
        m = "c65f67c4843110ad555134fa8b9ec51dd9c93ff9ad5d96febffd6c95eaed88be3cd584f749c1c561c46bb11e50bd1bfd939202598cbd7c3e274cedce0f0e7ce3c452c8f6edf2d640ef904f1ebe20e8baf4a621e82041324e606942c83275db0b87609b8819cc2c93ff4776c47ece129d238f026e0ef3a07691dcd54bfa2c8b7c"_hex;
        s = "116b58e45693d6c80065cef13ab2f33ed6c4d3b6c5048ca2fac4c793b962c1d8315f6a76e379a0b4daa8e1ffe096291aa9c18b9a182d6f4c5b5bb6ed02b4a0fd39388e4ca5772165538aad34313696fa2a303ff024e25a301997f94860080783d87c7fd24f4eb7791a3b6be09c3f3ad0221ef8268444c40fd845617416119761"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "eef211"_hex;
        m = "edf40a32aed24e14439d8db48e80d92c4c11035dedd30d90a4ffde5dba8439cd274cf0bb63c155807a90f2cf5fac7add8297ffc5a4dd642ceae1162031dbf746a2229b3586a7b71d5bc2d6ac27324e320c5f73031de10a1d7046010a74105d0885fe7368be8d5b340fbda2148f183f7213f1c8ddffeae6ab5cb907e32b2b525a"_hex;
        s = "4e6e6482b8f163fb3c32ff454703a037b9882eec1f82dbd675c94accd79a476e12a347d2e9b4745d30164ce8484635aeddf1116df40b516e6b2af497d27f2194cceb801922aa6d55c935ad166bc477c8e54ab29c07f432b0aa3808e17d28254a0431fd0267e389a6b852f10df0f9a2f317c6a6e762c7395e743b38341828ac10"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "eef211"_hex;
        m = "b1bd4eedcbef7c57ecab2aed92cbd60052ddeb201181969a7713d53fa18ad16716a06d36fd341f1e8decffa5c41e1d695cf11861fbbfec65aabe0cf188e0b126bff77111b81d13308b53a232ba68c0ff1e1d3df82186e8802eb3a5bb6690c095950a810764730196d0283b1cda7166ca80a8836eed9e32f2ed3ac925a363a7bf"_hex;
        s = "7a0225a29a5f3e4592843c5c4d543d14ac544a3eeee9dd5e795ffa87c4e16dabaf07ef75363d773d89ca712df7c32010d3ca024ed84a954ff9625390e498d04e2c676f3c51ebf0a46fe22ccbffa53c52f9a292886e6a8b64efe5717c527dfaed41d2290c79c18ab28a96ab5afd2f071689653550a64be24fdb5f90a8014df659"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        n = "8f705d5529b5bf74600abc485bc4bb76deb9627088e51fdd26dd0f37bb3b98a9da4094d275d55011a844884122daf8b4abe99d43d918eb50d9642436647f60577c5f60fb9b810147a910dd7dd610318392dffa3fcc41f89f461bb5be85bf885b672cecf00da3af4d7d90074c4c0144c4bcd2d49145f8097648ec7230747f7033"_hex;
        e = "d90b53"_hex;
        m = "10c21d2d4afdf3502dac1a791216d0c240b6b12061e0cf3033a7043380fd8756501cbe385d2553a6c7078aa909a3d2c22c2e9a743bd66503f6a8217ccab1b4f50163d916373b2ad80da17d8d211074213d76509fcede06f6984c95fea9e896b68b5f15d0be879f6f65429c2f40a4e066da587ca9043fda92815b09c103ec5521"_hex;
        s = "0411589c7d0860d41c7d4fef4d604b4dca0b160529209e762d5fc73df911e7bfdbe16feb0def70993e64eeb66888e47b3613256dfe04e75142ff2b325fd86b8e02eb01e4cd05b05cc788f014c170d584d092b7220a66133d4f0e949457eddc567eda792abe49b8a8fdfe177c6b6e0d7ac4262e95fa87c1277c46a759f9723cc6"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "09ffbd"_hex;
        m = "393f6cd3c89e67def9579e586c945fe97d567bae23c54a2e18c5f0903bc9df0b32ec9d9d533ec800c55b57dae2432234e065a52db1fd00ef27a043e35c15e9215167a22bd53856daa9586698e19735d08dd7e7a3996568ddf289b027ea5b467eded903e316371954ec7654fc31389fa7ccd3c978a4a489dec1a6c0c4ae42ff08"_hex;
        s = "327269d1d4d871a8be4ee49be39c5a51482fbe89d522c0d6cfb0ea6bf0c6f0b343a94222ef65058e27f5107e4f8d0ce20a064f19ac39189f221c5e62ad4fd7006eb1de620052bd35c268d5c1c6ee0f81e8b3f7f2977d2449167caaee2ca54d458108645268749651de6f7acaff09591d19ac99dc17d480ef3531ed4c14eb85bf"_hex;
        r = true; // Result = P
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s, "Failed verifying valid RSA PKCS1.5 SHA256 signature" );

        e = "09ffbd"_hex;
        m = "036f62daacf68776f409d0595509a596a544b085ec7649687390324e1db78538fa90ea7b1abb0d659f9d50231663bde208433e35cb0510b79ec375f1f6eda97e128f186cd5d7cee6d5d22f10b076e8339fe5251a4df005bce9da4a1b795f566b72f553778652b141be2ed5e8c84a0fcf92b1cdfc183e0fbe7a5e1b9351177248"_hex;
        s = "56c4af89728a322066b8c291b4f03da5a038e4a44ffd9b49be9ee5d1a800da1c58e7a852218eaee853f9695dd308e1a5fd95b41a441c2a6bd124088868fa26f384c9ce87849b2eb5edac55cb95d5dcda7bfffea621b3fa66e6b200ce755b947e778fbae07490410509f5036a07280f943b7300562926cdca3b20097f1ffc24e2"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "09ffbd"_hex;
        m = "8c25bd2bed75a33ac134f9c1d445245fd8e580d6148fae11591c2b65382f271772d0941eb0577d2b748c99e7500c207b56efdd56cfa7852a302b47384956a4cec089810ebe987af0e8e47a8b91c488902d2ae4170983539e3adeb74ed451e2815c98ac827f0043930384c335ff3507a347dfbea02be9c172617da42f3fe98a37"_hex;
        s = "56254367f71f6f1fc6944ebd29f8a5592095ebc73ff5222bd815da17bac7f12290f747deaeb29b98c98d31a3ea32508d7683a67d449c59a0d6c16b4855aaa7d6f170c02c5cef61c9b6889207ad021017094d24246c4c90a0de055f02a5984efb67481684667eea36ad6373c36712625fa18d3ed41b1dec22f3bfb0d534e52da6"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "09ffbd"_hex;
        m = "2cb9740e0c1b8867866aa81c64122295854ed681e8eceabf0651bf7a65bc23996acfc8566f4bf42c151b7bf7db94eb57f0fb065546477549e829bafb8d4a67086dd48d87533378edf41d992e7fcfc425759a9c36bb9f4b32eed7767af6566f68ded0adeae25c7a70ca78ec09774d16c8bc357f6d6f7bd441bf62d942c768a580"_hex;
        s = "156747b263be659661e5e35e363d0523303ded9eec1e751575ab3a43156773a056acfd0daaa68625b1cc068458ff9e40ae167594bac846cca2b98bf6e5a4a01e961adfcd70206c05d66e3903a64b61afcbd17391ad0db529944fc2d0d7be3a4da8091cb75910f670d9515ee4f8ff3d62307eb54657e03a330e3cb0661e6fb796"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "09ffbd"_hex;
        m = "127498bf44b97a4a4ed7ad4bbc7c3781e2f83a53149fc95c1a6efa27def23d376866ec4b0c1c23e0e21ed1f677140f17c268b1965aa91b15e62d5749d4fb64024ee7d06569ff897ca026f0f282ff2f17a70dcc2ae8187fd8cfd241004dbaa6b9ab416c96c32b5429703930c543053e88782db49928b39cafc0a4e2d3b1f8ac66"_hex;
        s = "1976fe18cf82bf6ba851626bf94509348f56866930c771c82a6e12c30735c283694a0eeac9337e407525e0a831ba7eff77299c6896a85050b960718a40d5e34b7bf71eae4cdfad0d91d8fa6dfe37f30679ef444ccd360971ddc47e038123b7eceb3072f370796122aaf0b9427563280222328fc0068ae1dbd39a033740789536"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        n = "a16c7fcbb8d6fc602277e9cebb1790bd14999ef7670400c0bd0ea6116fc72e29b868c8b62ada0e7b4cd351b5a76c177f158b4f724f1d287d66df114eabd68e3e8d12409b69f96e334c0daff79392d184b9102ea5c4ec13052bfc509d9ae76851e8557a417b86e9d37687d243cf48812ce621c5f39404cd6b22a60beef744a42f"_hex;
        e = "681201"_hex;
        m = "e24695128cc0f0e9905a6dcc1c54e481ef431c0426a13e2a51888984ccbb48864de601e8b927f04d3cccb323985f47cabde033f89b51035c3478f881f5e0fef64621deac6061b59f5e1ba5b8971fcaf22cda70bdddd883a021874621753e48e9f47d95242877292720cdaa55c29d564363bb3a1a953ea43d403fdc2cf5dd0fa9"_hex;
        s = "88b9604e95ccc993514a258d5a6785836b3c0ceda1f9a8359b1ec9592100c9b47572fb17d2c24dbd6b99ab46c408b7bd4b8094a44d05c2cde1145ab516b36926358f980ce1eb2e92793f65f34f09a4053f8deb77025052e12922e3f14823859d7e49aa54b7a7f0b20c1672e1a278ec631f955b4c19da05dd9c1f4487a0e08f31"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "681201"_hex;
        m = "820e27d35ad139ca305e9eb26c128ff59dcac86f05522e7e5721b458bf437fa22396493ea93903647942bef4c4afcb0a05a021d386c300a0260fd4395bb55c7473530b061f6baf983115501ea5f05b64de5e00e933f1d8f1aa20cbd6033f319ff9ae37d3c4508490e23e1dd717bd862ab36e2b5913c5fe996abc60d6c2c945"_hex;
        s = "519c717e336e7a28d648acf178931f6cb958684979b23e1d53ad32aa242e327699ca1a1f294feeb8b6ad8668b75a3e42ca4ce08a91c3fcae06c7974e6d9e23e622363cae4cdcd1914d31f38f95002b1a6da863e70c244411cb1be90ffea30ca4e345429e58eb751f676ea7ebee4363c552aa5bda5d57908fd5a87142db8d9821"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "681201"_hex;
        m = "d8330fa49a0a75f27470a2898ec1134666515fb467ad6b74be23dde26984d3f59028d467193307167717a2abc25aa6790d9acaa8f4ceb49274ce6f6d00161a2bd0c6dd9e7dee22e0cb0901f2c5c7fba31010ecb379453b39d0c95442f9c058bb40161291edc32e16184ea5a7bf907c8c16bbae1f1e9b6730791b72a97d0af56e"_hex;
        s = "5a692ebff6a43c5e63602018577fcac17415fcec4087e4c41065da33dbd7d87862de2e0c003bef2ebd0a411884811c7fbfa893590ea885acfb023857b904b0aff0e5061f2fe3376be5ae4de0510b2c34be6e0192722e63dd6f3fa9a7f8a191b7160997c463d7f7d46577e6cce534da08d1e5245b3a03b780f8144070cb66e6ff"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "681201"_hex;
        m = "243db9a1c203c792db3204bbfb3cea400d6e5efec0c935092f0df759c016e3c04c6b331f8115a1da85ad2989dcb911f18c3927327f7c4a4128382b996ada552eb51b6ba372d4b1bca113ce16c06ed116ef97711f53319908b8e224cd7aaae584a573ea935be90121768b7cca6f0232977fb2c62d03902c442533685bb92d99aa"_hex;
        s = "8d1a40fbd8186e3cd1dfbb529e1ee9ab13a6c8e6cf04e663a4de2349c05334f0ab3c694ea89397ca3e70a2a1957ac75a6544842af88cbe3ebf641f68cbce75638da1c953c3f594f8ee8b3825ab4aaafb9fb152f05bb7dcc07e3b666ca8626e69bb262bc240398007b871b7790eca96512d64f3ff94470224fa075ce3164cb1e1"_hex;
        r = true; // Result = P
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s, "Failed verifying valid RSA PKCS1.5 SHA256 signature" );

        e = "eefc9f"_hex;
        m = "186594f37c9ff1fe3ef55bbb511dfebdcf5b64723cacddf80f4425326e3b411c3a84aa5b4b1ead19fd8e120feb8cfce3fafd10b59a21d9f5480e6b77575d47c9f1237fc459231b617241bace853a7dc13f93200df9cf6a733de5c8ba85f13501452a5c552c14017fa7f79d1fa88f48ffa505dca1e31e581af4b382237f61d16e"_hex;
        s = "9301ae4d76e84df108b70d94400c0b2dbf0b024fd5cdd5821c408ca2f52b7d4466a43abcbd8f40e9c07c4e4e56ad1ff471327e2e997d4e372d82c3e9f9db4d40d4d6308b4f7e5ac91c4ee2c194c038f8275dff82b9cce56ccbbd2ac3d12550f184b1cf938cefc85afc588c45c1ea055da0d4dadda266895cb4b84b846d8fac13"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "681201"_hex;
        m = "2ab6c6ad26e227177b6458a1caf18bc083c162a1f18b0fbc77b0baac19b7223e3df988c8b39dc9bcf4c7ca7ca70d18706a2bd057cef7bddaa397c16777f1763c596314c2e3b4961d774b1801c89f84c79cef6dc0d1333bc99e52891f1c95cb75055c3444bb10d7638c580cd7349015eca37701850127d1b0f04bda7d118c6a11"_hex;
        s = "8a270d2b49cd2897df192e12121ba6b92304e89a429753727e8cd7fd8395ee72788ecd58d91ab99b4385778fb8f9a5458a79790def0c05de8b5646c16f2f8f67652708573216f13335fbac257e4f6e46119fe5b50c309a7c01731c8f8fc240fc68f08f25879a32156dcded375c6ecaf0bf861066de3a034bbc00844dc74b8b6f"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        //[mod = 2048]
        n = "c47abacc2a84d56f3614d92fd62ed36ddde459664b9301dcd1d61781cfcc026bcb2399bee7e75681a80b7bf500e2d08ceae1c42ec0b707927f2b2fe92ae852087d25f1d260cc74905ee5f9b254ed05494a9fe06732c3680992dd6f0dc634568d11542a705f83ae96d2a49763d5fbb24398edf3702bc94bc168190166492b8671de874bb9cecb058c6c8344aa8c93754d6effcd44a41ed7de0a9dcd9144437f212b18881d042d331a4618a9e630ef9bb66305e4fdf8f0391b3b2313fe549f0189ff968b92f33c266a4bc2cffc897d1937eeb9e406f5d0eaa7a14782e76af3fce98f54ed237b4a04a4159a5f6250a296a902880204e61d891c4da29f2d65f34cbb"_hex;
        e = "49d2a1"_hex;
        m = "95123c8d1b236540b86976a11cea31f8bd4e6c54c235147d20ce722b03a6ad756fbd918c27df8ea9ce3104444c0bbe877305bc02e35535a02a58dcda306e632ad30b3dc3ce0ba97fdf46ec192965dd9cd7f4a71b02b8cba3d442646eeec4af590824ca98d74fbca934d0b6867aa1991f3040b707e806de6e66b5934f05509bea"_hex;
        s = "51265d96f11ab338762891cb29bf3f1d2b3305107063f5f3245af376dfcc7027d39365de70a31db05e9e10eb6148cb7f6425f0c93c4fb0e2291adbd22c77656afc196858a11e1c670d9eeb592613e69eb4f3aa501730743ac4464486c7ae68fd509e896f63884e9424f69c1c5397959f1e52a368667a598a1fc90125273d9341295d2f8e1cc4969bf228c860e07a3546be2eeda1cde48ee94d062801fe666e4a7ae8cb9cd79262c017b081af874ff00453ca43e34efdb43fffb0bb42a4e2d32a5e5cc9e8546a221fe930250e5f5333e0efe58ffebf19369a3b8ae5a67f6a048bc9ef915bda25160729b508667ada84a0c27e7e26cf2abca413e5e4693f4a9405"_hex;
        r = true; // Result = P
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s, "Failed verifying valid RSA PKCS1.5 SHA256 signature" );

        e = "49d2a1"_hex;
        m = "f89fd2f6c45a8b5066a651410b8e534bfec0d9a36f3e2b887457afd44dd651d1ec79274db5a455f182572fceea5e9e39c3c7c5d9e599e4fe31c37c34d253b419c3e8fb6b916aef6563f87d4c37224a456e5952698ba3d01b38945d998a795bd285d69478e3131f55117284e27b441f16095dca7ce9c5b68890b09a2bfbb010a5"_hex;
        s = "ba48538708512d45c0edcac57a9b4fb637e9721f72003c60f13f5c9a36c968cef9be8f54665418141c3d9ecc02a5bf952cfc055fb51e18705e9d8850f4e1f5a344af550de84ffd0805e27e557f6aa50d2645314c64c1c71aa6bb44faf8f29ca6578e2441d4510e36052f46551df341b2dcf43f761f08b946ca0b7081dadbb88e955e820fd7f657c4dd9f4554d167dd7c9a487ed41ced2b40068098deedc951060faf7e15b1f0f80ae67ff2ee28a238d80bf72dd71c8d95c79bc156114ece8ec837573a4b66898d45b45a5eacd0b0e41447d8fa08a367f437645e50c9920b88a16bc0880147acfb9a79de9e351b3fa00b3f4e9f182f45553dffca55e393c5eab6"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "49d2a1"_hex;
        m = "915c5e4c16acfa0f49de43d6491f0060a944034475ba518572c08366a8d36c7f1e6afc11e5e4649757bf7b9da10a61d57f1d626847871d8a2948e551b54167c79de88d3ebd40a3e35809b996a53348f98a9918c7a7ec606896ed30c271e00c51953dd97aa6a8fe1cd423c3695c83fcf45120ec0a9cd1644642182b60e599a246"_hex;
        s = "3d57ea5961db8fc144301ca4278f799911229d865ea3e992c7fbc4d03c6551729e26034e95dd71da312340e4051c9dd9b12f7700a821fe3b7c37785d5106350b667ac255a57c13da5842d90bcadea9e6b1f720c607d6893a2caa3c5f3c4074e914451a45380a767c291a67cac3f1cab1fbd05adc37036856a8404e7cea3654019466de449ad6e92b27254f3d25949b1b860065406455a13db7c5fe25d1af7a84cddf7792c64e16260c950d60bd86d005924148ad097c126b84947ab6e89d48f61e711d62522b6e48f16186d1339e6ab3f58c359eb24cb68043737591cd7d9390a468c0022b3b253be52f1a7fc408f84e9ffb4c34fa9e01605851d6583aa13032"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "07485b"_hex;
        m = "03d2f0693517cffb2b724c1f30502c5359c051c1bcd88dc1dd54b89e6981009d275a813b2bf016b74d0f6ed0d91e62d0884785c9afd8fd1fb7e99246cd4005cdda71a39cb649197a996d8ad2d23fdfb6bb015f24ec3d7f88af64fb83b4b525eb06607d133eec834cf7d6c9ab817b4c0dda370459d9cfba05ad0c1adc86a909fe"_hex;
        s = "511abd82218cab344979b2887b02600d2427f1eb12ac01d97684c2a443a9272834c3f79cded07a39dbee3770dde827a74dc994b17bfd8a26d07b239d26d58c42f79d560264c31b7e1c3dddef6d7556f228c394414f4cec561c3da2686a8eebec7702f32850809a93deeb84b2a02fcdba224d2fd9efb8e056e796f49b57d56e9f3e90d0b49b08bdee93a2e12e676fb4d4fa838c5bd88eda008f1b592a72465587be0ae17d9b156b904f44a7e04d3b58d24ad67b71b0f4c699fa51639546b62b9f83597ff03d465f1bb396ae15e92d0e92e85647d5df113e2c7518d0e3ad2e7aa7dac720c98347aa151e4f37fea081dbed350cc9c93f606b38f21a3e5de6d140d2"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "49d2a1"_hex;
        m = "dffe42bfda886e1a73fe8a8dfcf71c9fb44deb054588a9bb9199d554aecce08f2ff88f2aa6f8a0fb675fb03c8e685c27432ca7c33c189bfd849d34fa7b2979ac1f57eca389632426bae0b98398ad60a3342557e14e96041c1bf4d90b46cf7ad1348322d28caf43c4f7e86c0924ae703c109ec50a84ea2a43df078c3015a52b28"_hex;
        s = "8f4dd479239f2d08dc05d7d40539288b67c4d77210ecb16be76f0b1925e8b088570831e361a1ca57893135f8af64b8e2996b8d635899da4e04c68acb9b1b3813697d57da90c57f18509e0ab6705c704feb448cca5c07d258ecd884ab93f508cefdb25f2bc3061c4006099e2e33b27972c3edb0a0a33114d381c82ab506d041ff680af595ef3400a8bb6774030d2e38dd304272092bd32a553017f7bda4b998b27aa8aca12def327b1f11063a5342b0d55738183417d321c5682fc4ab64e79174216feebb989521e1e3d827647068003be34fe1d093964d28f4877c49b4065672448597a89b91919cfb55ca13836e7e6f3b3fd04f417cf1c16d9872538bf4e87a"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "49d2a1"_hex;
        m = "cfe99788f55ec6944942bd0a187d51b80fd8bd4051bd4f07c73e614eb75a8b9f997b176b2642b5f1b1877061ba9ce142c1d2a311583f072b7cbe08ed253681191c209d7b0d438fcdddc284d93d59d6dd80e48333a921dd31c9b6834f88768f8701e01102d3e8bdf074fbe0b8c93d9951f41545ef6eeb3be35530babc079f1fb3"_hex;
        s = "9fd6f6107e838107f906c26cb2910704599f175b6a84db485fbc30776eb7fd53bfe20c38c537b154a3e519b662bd9fdc8e3045e21f6e5ae97d0ff6a9d8632825544525d84f99f80e3ed4e69dc5e219d59ccfbb37c23c84fe3b3e6fb22f402f94e5225c6387fdf8bcdb3508f8832908fe05771521e92234348004e8fe19a8f24bebcab9f074327c88d066bc12081748d696be6135c6aea32220ea786ebd7800e6936365ff25831c28cb6c8a59237ff84f5cf89036cff188ee0f9a6195f2b1aca2e4442af8369f1b49322fa2f891b83a14a97b60c6aeafd6c2928047affda9c8d869ff5294bb5943ad14a6d64e784d126c469d51e292b9ce33e1d8371ba5f467b3"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        n = "a17a08272e656cf600f4650ef0952b15d568d9fb7f1b3f3559aa3792743f7d895e4e26dec2bf09996de8a99f7c434bc25b0c7d61e83fe5647c213b19902abfa053321a16048642cd3800de26172eb39ccab029130ceb82e5c25c676e89007cb00666a2d8f64e59fea64628cbec9c361abe25841551db01f58b80ab17f02a93cbaaffc2630ffb6f56f206b8a6f8e0f1e5790652e7c7227258dbcd5924e94876f983ed02e4e82272f5d44967bc501d1515d80dc25d5c838d0357d0d1704b0253d6e78802c02931000fea2e865c90b266c8a0b472e8eb17456777973342da6978cb45d2100cf91ca6f6d69ff30ee8f3164bfb180de0b355c067bd8f1a8544b9aac9"_hex;
        e = "66a13d"_hex;
        m = "41c00eae64f3e330222e114541eeb5eae1a705ca0c0687a68e7982fa07f1b3de3ee7402ab89df2dd8aa69ec06ba8e4460d611cb7aee88e8dea35e11fd3e4d77c4336379a71590ab0c3e909e0e3b6571915c86c3cc8a0517d6ac1130d816f72f6f8b7d946b6af936f76ff3beed2a0742ba0e4dba082b73a3eb924ff0c3a1bec12"_hex;
        s = "13165444a1f039da049b998e332cf7655149975713b5378ac5772f2e176ddbf338a25e297d873cca5f19eb4e4157c532d06249d1e99c2857f8d74bb74cc7593bc872daf5b45541a373aadc43a0711b3b2f27ccfed06d9578b2a3c7d10a12e398d0302f86e05f154e3cfd2a0e072aae157cae529bd5688fd0ccea22f58181d069eaa0957a5b0eaa2e3f5a4aeaf3d1512a43dd2f8434579eb57e23852d7323c5dd22359e9dfec59dd75ee3b8e234a41863fe0a68c46f777a9f48887a786cfaa40db1c7d9e04efb8a882d8169764b47a013b5d1d15f4cbf758adc83c53e9548e77de20f14b3b5f064465beaaa32ee41755aa48264a14df837ce5fb85a5ab91bf6eb"_hex;
        r = true; // Result = P
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s, "Failed verifying valid RSA PKCS1.5 SHA256 signature" );

        e = "391c9d"_hex;
        m = "671ada018b6132b381978036f19cb9fa9cf7d07334642cbf718c59896113fe2d00d70f1c087743830a13c927be53379398abc3769bddb54772bf1c2abd3ec017a9a35939c315fe940e5fe0eb52f438e1b8307e5e94e1dc348206e203b4d77b5a8a05201e63424b30b4042f4a5786a62a25106bf3c67989d0c8ea13daefe4163c"_hex;
        s = "2942af5fb4e5230990bd20c2095fa29e9aefe6e6489111971f0dd397e8d461ab3f59c0f29b86d11ff187984c54c51b0bea35f479a4b83c33dcc8f149f56eb9859a71e45f3a33b83d30eca87bf19803eb5888ead3151d9b673546e2c0dbdb523c34331cbd3a83baae6b55dc465de20d40c5bca9647d74b8399d6e40404828772690afb93b314a55efb5149603c8421fd85ba5b61828c6f679b53f929398d87affb8929e4684631aa2e86d492d3d7c9a90c58e465080442f69623e4eb2080f7af2ed0442c0bb3f0eccf45d4f075e4474a2c058665f25164c457fd19e5852061af9b232cfd2eae7b60001364c013a1155a9af18cbc134d1ee8d30c157cde3a9ffbc"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "66a13d"_hex;
        m = "be91864d3728f895c689f09b28484138e0afa29589bba7486a68f0bf4b2ea1e287cc11f46344c7ba9e27a2e049125798d97921847ba3b3d6a7f672b6f875e1e43b875c9ec6fa0ac40b470d3a6c18fb8e510792da78a9a7ec8dcb60a5fbfba39f014bce120851a9f9347299703961166170e25e5f2ad46bd2446e2355fbc9d05c"_hex;
        s = "631529e0b149ee1528d514861cac711eab8c01c1c22c7ff6ccbc08783a1ccb2748c22e57a1deefa867dcb1ae74c40b1969db2cee64c0706af8daf4c9e91c12672d8f0849af4bd0c4c5f8e439a3ba7e3ddf38a9b38db545410dec0aa40522d6a3cbc2ab53a838298f0b93ae7d362158f04858fc33ec03fa6d3b7ff0f27d74cc4abcedd25642f4d259d41511456004c24385ec32553ae5d5728a8f68707ddd6bfa51c2f4574e1c96ef4db0715675fa4fbc57b9091759eda387e16057e9d89797f61df9196044b98667866e12c5132928eb735fa2d02c0ee7e08ed68d80fe1f76bd85756a3967c6d3e1378a754fecee72362928cb622731bb01231758ebcb805f5e"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "66a13d"_hex;
        m = "4c2d1103c36e96d179291397b1238177d4af3b6fb9dc622d23ed80258b096be020346d970d7ea100fa7aa068d5f25d02d2d94e7fb081cdde3f0fbd861f2b7092cafcc86cd4539d9d72265fe33a41fd84293805e3eaa00c51557e502537009c0f516b6ca9a355524fea149831677627a6e2b3a7c4ef9fe82d7024812b5bf0b700"_hex;
        s = "4d8b5ba1f5409f476221b3527be6389c1ca3eb50cd62113ad2f712cb2142ceff3178948670c9cb7dccd44896ddec9c0eba228370cb23919610774e9d70d6eade95865042edca6e90cdc007234400591e1cce71bfbf5a546548d483e68905113693a3d1719ce376e72b180b7f3c7ecd13469b8edd7ef95d9e330d78cb36e37b50e87d161b1abdec433421a3a65b49b39cacde0678de41df894d6a2b0f171cf91052bf0f0bb7cc89889bed7699e33540b4ec8f93ca2c690783dc5d80fa5b815aab0feb3ef4f10c0cb46496aaf6dfd2e5b3a7dd64386ab9a4da0319bd927facaea80ba5f4b1d71e16fcc7550fd8211756c35935507a32f204858e2b475d28eb56c8"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "66a13d"_hex;
        m = "e896edb0455f372c01d222d40af9298bc17fdbf450b4d0923dd7e12d4095987752cde6ef079614061d83fc805526791e81d21c7adfa52132a5c6a148ddec09c97320caad8dc352ff1ad23c3eae69c3028d867de20610469602187959dc5e6791731701b27eedd860204848d4bdccef800b2364f66cfc26067b53d326e4f39b18"_hex;
        s = "6e21208ce42d4ec6512c300f6f9c0d43163eef7e05365448380ce3fec34913a701a5e30455556335101af1ba40ea69fc17b30c4192730336e8af2094d36873cc83617a3feebd2b09dccac1b31b9352c1db3c3dbb7ea1e774578e44c92ea925dafd9de71c46d3f25eb015199150e6e8c26ee612edc3fe2f0ca6acdca9274fcaa87d97e104112b1f85d1c3f3e92f0be7932613afe5a683c0e52f9234fd9ef979844e277e31d3c2b725bbebe97a9a8e619f8308c01a9b3ee48e5dfcca5b153e4890effb297ee0fecd30fd71b6dea0694530fbad6c65abc4621f23263ceaf2cfa21fcd19cb180812667e8b1ae108323ec289826412f124547ddd92024c0ea9784654"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "66a13d"_hex;
        m = "3f49b00ac1f9255907cc03f9b45dc787c250d9d6833fb389e2f746e1ede599d390cbb45ea3b7bc1b28365f16cdc573dcb988d9d5843fa8d4877587ed57fa5b878c9423b1c7f21fbaf3e138fbcac39cf89b3ca9a84b2e0c109be82a17a89abf95b80cc4ad3390975df0365653b23e8b02f3d30ff6e0f62864a4b8f506e9ac0c25"_hex;
        s = "90ac97a93a9f6c5c6e268e3464b6d547dc29bff8797d9f776e2f56fe1c30fefbb679ca9fafba40f400f08a5163d757e638aee083084581b760ab30071e075f90183db328e1ab519fedca1ed92a1e4e473b538e2470606b5379abd2e4b73f4c132e30c115bc34c73019880571c30fa6c6c1e320c13022317cd3acea8c520f87cf054e84be89a952202fc3f8d0d707cd8806b8b22bf2c0d7bf884688607a05b635210b9a7e2e1d2a28e324c1573d363d5a76ea0aaac70480671caa4969e5177448e62e76270197697fcaab720d811588c8ab540f053c8b23b7cefad205fd4c444bd5e73d80c62451158331face2b6f7ddb034dd5e61bec444f68d0c7e39d2df940"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        n = "c9548608087bed6be0a4623b9d849aa0b4b4b6114ad0a7d82578076ceefe26ce48d1448e16d69963510e1e5fc658f3cf8f32a489b62d93fec1cdea6e1dde3feba04bb6a034518d83fd6138ea999982ab95d6a03517688ab6f8411c4a96b3e79d4141b8f68338a9baa99f4e2c7845b573981061c5fd29d5fc21833ff1b030b2deb651e51a291168e2b45ab4202dcd97b891925c75338e0e648d9d9ad325c10884e1fcdccc1c547b4a9c36aef939e8802b62405d6e3d358ffa88f206b976b87f8b12b827b0ee7823f9d1955f47f8678f7843b4cd03777e46717060e82bf149b36d4cf3d0bc7e4d0effde51a72f4ced8e8e5b11bdb135825ff08873e2f776929abb"_hex;
        e = "3c7bf9"_hex;
        m = "fc8e19e3b26bbf7c8c33a452b7ee02cbcf56fa94a58b7cee3e0866481fd6f013c7ff47d27e4678704d1590d74eb701be26c748c2cfe9cdb99bb80b4375fff0a16a2b87cb6900d4bc478c00110659b6d257e7cc905d5926b0b46fd706b2b48aa6edf921f6fd019b08837e3b276a3ce6b06c9dce24d8454d7a931613ba5d5f84c7"_hex;
        s = "058bcfa4b10ac6a73918a07b9f0a8db1ebab9a0ee5c7f0a2261b98efb3592eeb6bf45fceae24ff20c2683e1b33291f49a7f86d7fe239c58a45910a14748e10c25a4dfa693e5a77138de2fe5f61de0a09078cd0d3c61b1e740bca7a3d4048d4fa12fe69412438efa18216819be40733500acd8087f429da734fce6a97fcdc9c32991dc847e4d653260890304f378a10b7754cb4ac5efd7a3db23bd44b6542b81ae9fc33edca6eb1570b1a39a0b8976626c3892afc42e6fbfa8bfbc191c3d026a6248e7ee391f977ea5f0442306ce87702ced7b3f00bf0a6040604d0a663859737ec6c04dc84763d1cb63c4da8381a08cc52b370ba09515b93d9a6d3e47c5929aa"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "3c7bf9"_hex;
        m = "4c587ab2ddd6b13bf7a916b5d571d7613f24258201b1421b9de4dcfb3d8a99f7ebd5f37704024634ea38273ffab4f846be23b913634f21556dfeeea3a91779be63078d16da637990f1cf6487271ee111c9bbc483674733378483008c9171362f1db6f199464373d97334759445f8bb4acab3ebdaf4e09f494a3bb9bfdedef7d2"_hex;
        s = "052bc5efecb052b92821c405e6f22cf374dd1ce4bf691eb8abcc1cd01254a6e51fe9237cfb9cadfe32a8780135949399b048d26f5de49bb9d008d39b749527eadd13066baff87765eb255021517a2ea69e45bd35db1fba9219c94f944b2c9a33a37779505c8eae52d6061988d152f9f51f0002e545973402294dda7f7c7cc3135c37ced8cf723d4011d1ac16bc1d0bd670eb7f63f079f30dad8cf55c326a33bc1684ff17a91509f4ead4f93c3c0eb6679eab612e05fc71b936c99ca8579cdeb9f26200a4bce89e330fd5d84b1ec98cc1d758243001fb18bc325b630a58154c2d38a5a8ac2ae6cfa54a20f7580a745c206990c142e8a580eb36266a3a9602a8bf"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "b53999"_hex;
        m = "425994d102a63f542766b12d5207ace27de9207630c2fdeaf741450413f1654f7061c563d7829e6665500cd33cb4647a78a9c7c9659ff749ef1c6a6b59a99d8532ecab1885121e54517005de386947d07b923602261467888852c27be6ccd5fd71436d77741f6825d20dc5d5b0ecfdeb6fea96a9ddeaf5adac2a74bb2322b4bd"_hex;
        s = "c1f91aa430083ad84ca80ffae2d1ac2bee9b22bd0947175ffd03bd294f6a3cbb5ac63afdacf02f7a6a274fbc33f8aa25cb08174c9c4aad0cb9cbaf02e6f72a8deb6ac52ba88da773b4fd07b33144b9a28a23a1db150cb095cf03b208e80dda3263806b6b0e8eeeedd624d4eb8028e6b98ef2a3e55f38f1b0041425cf7557c41d35d4b0383448c800076eea2c22ca2f333496bdf53564f39d76822f55cb767cc1c2d516a22b4c6fc1525608ba61eb42c04c788c7050a48b7f3a431b2553dbb52cc065a9869c49cc021d7e448dc7012842d3351f98820bccd4fb7640b85fb431fbccbfd4e2544b6f3c7c270326c8cbbd216333ac82260c5edb47a301acd05c7c7f"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "3c7bf9"_hex;
        m = "bf082fa4b79f32849e8fae692696fc978ccb648c6e278d9bde4338d7b4632e3228b477e6a0d2cd14c68d51abdeed7c8c577457ec9fa2eff93cbf03c019d4014e1dfb311502d82f9265689e2d19f91b61c17a701c9ef50a69a55aae4cd57e67edc763c3f987ba3e46a2a6ffb680c3c25df46716e61228c832419e9f43916a4959"_hex;
        s = "621120a71ff2a182dd2997beb2480f54be516b79a4c202d1d6f59270f8e4d4dbd625ac52fe0e49c5fd69dc0d15fb19ec58c9312a8161a61cb878abcb11399937f28ff0803877c239ce0b7c4cbc1e23eca22746b071b2716475424c12944660b929b6240aebe847fcb94f63d212f3aa538515dc061e9810fdb0adeb374d0f69d24fd52c94e42668a48fc0a57819952a40efb732cfa08b3d2b371780aea97be34efb5239994d7ee7c6ab9134b76711e76813ad5f5c3a5c95399e907650534dbfafec900c21be1308ddff6eda525f35e4fb3d275de46250ea1e4b96b60bd125b85f6c52b5419a725cd69b10cefd0901abe7f9e15940594cf811e34c60f38768244c"_hex;
        r = true; // Result = P
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s, "Failed verifying valid RSA PKCS1.5 SHA256 signature" );

        e = "3c7bf9"_hex;
        m = "bb40a410b0183b32df12f739506643bdd2fa7e6aed83974918ecda402cfb09dd1932af4fd7f3b1b5a0e8269c5da268c25e806b204dd34e28653f304cdf6545bfadbe297f6bca7493936b8e91f08bc56455059c4c8ec36626972414ee0ca04c82e1aebba953e5ab531e62d823f16b7f2a1f51b9f6979b07cb16602e309bf545ad"_hex;
        s = "3f6909f674d4c9c2c26b66d8ee3d7702c560b193a8fbfd0ddb3a9dc909a6eb7aa74d446b7993cdd5b7e272d826281e4cfa08000d2291c2ebe3ee6a77a4e03a79248385359d0885c61c8ade8cf4de7c8e51e879cc1e6089a91a56dc58d2b239e185e9afebf733e2f0fd061270eee0670122c44fd17af6860b6f59690a1b2a91e16522e6a75903bf4e6c97237825f0b01e4c236052b173a8d91f910b0c903590e16d7104609ff9c0194ffe0c09dac1969ea08b01497c8169c7357e8b1f1040604dc0f8b967bfd075284736aa22b0822d3cd13c48a8169413e0b6b26af56c577c829b38e3fb5c4ff78949634d14ff3a40d0d43584d832d6b51d4065e0900ef197a5"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "3c7bf9"_hex;
        m = "56db10c78e9fab7c1c356bf8b38e4adcc464ebd1a3cedabfe812144016baca547aea625656f0bf2e3f1dc2c9c4d310c650e01672520a4bf79aebb5d00600af805ffce9847e62b086b35270d367a3770fff33fb28047b5f888167b28fad647940cabaae3a4d1c08ea3f7d7d00e326061f9906a2d902499dda652c1263520faffb"_hex;
        s = "8432cca3357f5ee765bd37dbe2b2d107dfd840f8f720cf4a80144740f96e47529c553fd503a25bfac61ad76a24386af72d81522e6f05b66299f6aea3b98b23838e7dde04db8f8b0f32ae393f6bc0bd7070e566ba1fea53ca871d680f70cc9585aeece672d7c64c228c49bf1ce877dae73f9d8756433f5edc4331415d51957d23e490d4f25317d09a3ad06ec9229dd706cf593915cb156d7f7a32d68e52ca27aea7087d4fd1e194b6029246694742dc70c5136a26cf41b3abf9cf9cb65cd2e37ade6b9fe5ef6160279871230f35758f02c3b37789c1d74df0dc0f97f28bd789755982dd249c0960e64739b3c74b9c55ab810650529e7243bdafda7edef76fc748"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        //[mod = 3072]
        n = "9bbb099e1ec285594e73f9d11cbe81e7f1fa06fd34f3ec0b799394aed30fc2ed9de7b2a6866fde69846fb55a6ab98e552f9d20f05aa0d55c967817e4e04bdf9bf52fabcfcfa41265a7561b033ca3d56fb8e8a2e4de63e960cfb5a689129b188e5641f20dbf8908dab8e30e82f1d0e288e23869c7cac2b0318602610a776a19c1f93968c652b64f51406e7a4b2508d25b632606834a9638074e2633eb323324b8b30fdbd8e8fdad8602b11f25f3906439055afe947f9b9bcffb45dad88a1df5304c879bb4a6eddb4d3d1846bf907d2ca269845c790b2f0af8154aad9c4acb75e18a5d0e4f9f88137032b9964fe171dfa0d0f286090790f52157179a6734b5f9a64e3d2ed529722c3d3836d4501496f927a0f8e389ca35332b836d99e995f4a3e86f581bf9abdc7a10e06a6b31296ae3b43e6ddc9a0d9a7d0d9c4053af0875e851192d1de7b08d1beb7b857e227f8803a5620726a31920bcab922d3370a78033b315024a0fc1f6c276be565e58de77f294c8089ff4c43fb334d26006ab5757c65b"_hex;
        e = "ac6db1"_hex;
        m = "921961e184a5d9657697e3e65ceb1ed10204ec56e739df0e4f906ee194c9ed27bd9fbc0d514abe3a6e480cb3155debfcc8d9fc815719b334f7500a769488773b68e31b69cd273c824f79f58306692c0c232fc5c0c83415ef1dd59a73a063e9d7bc6ee7bf9e433c8344b3051ed616c9473a90afdde393ee88e9a5849e5f642b43"_hex;
        s = "55362a6854a7846c4d105dc8a358fd4c02931f117631968457f422939d266682fd705e2091bfd5d1bfb52b4bfad684914489ecdad9038b75c65916a9e967630b16c76656b58404ec11ac46d8684b3e72d4392fb6e7e6c929e43ad4fb6ce6198f241b39e8bcbbc058792dde31b195b91bb14236dcb82c28a5c24d633dd847d1548dd403b3a70149371f46432db1767a00c462758c2298fe9f1f04c2ff4b96858d084ffe5a624cb85c1f9be2a60fed40133b7c571c6c467f46a0f1e48ee6e2e6d65424bf8196b0d927e0fd4141264aa5df4129d52d2fb57b8dac9386a84ecd34ecb1feac3a2b99d055eda977ddf8027f1178348a30e4cb4ecef2291d7f520794018b39f5251fd46d97282ac21f6bce6539d19aa1c21c3c220a2ddb6feed262eceebd753eaf5e0eb98cb3eb7d324a3dac0a415a18b7f36170676e8b9d3e421a6f77046bee6d9591c93f7ef0242f464f15b63132a0aee80949709429b1e76d40d60f79b2a6ab362f12e2cdd0bc66868c80278043e179a36f2815e7916378b0fbdb8e"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "1ed02d"_hex;
        m = "8568ff68d40c9f240b5ff56d8919704a4819fb48b2f0741db6a3608a1aaddd861344d79813dd7f85e2f2f92bf00355adeadbc1d08b14fda5b5dd0f69c0fb37a9120e25a9ef166a0793352d9c7eb71fa3104fb11d55a38474220b205e6196ea04a94f506412be47f347b1f787dc3cb475e2fe31f6b9a6f0d026b6fd32a587dcdf"_hex;
        s = "191cae43b354617b1ebedb701c124e76339935835a3633b4f806fb835d0dc4b7e4abf00f8c575fad8467ca35bc0d37b58a90db835f4ecb9f1dbfdfaffffb6ef1e0b894dd65fbf8e36478adb673b116188d864f185be5fcfc17bf1e6cfccd499d632b3cb1722c75776cd4d8ec68d2512c1ca598b970f03f6fff5facb107c0e74d6aefffaac20f8e3aa6e825a1de1690a84c8ad1e766642f2a89d3032b58b8e6ec50ef6a8e69b6afd30a2755d42b55f9e21f69c8d9d993549d198ec6c17d12f09ab4be0209030dcb274afefa77fe461e6469ad51f56dc58ad2f06b620af36ba712fa798d9812d2b6ce8ff4554b58bd2a6a8abdd8d00920bc3ad3b61586e544eb073419a85bbc1dfaf775068dc004a7f0ae789d5023d013f3e6096ead893158ac4ba050b87f8186705179f531be573d9557744a70ee42a4b3eb89c824eb8ae1172212c177557267ef04157f9fcf003c2d1f6039671d3af71339c30fbf772f14b3d59e81739ef82d61ab61475e1b4c835fa50350da15610f45531ae85fae5ff9a31a"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "ac6db1"_hex;
        m = "88902b37b0db4246c41b50f180eb1350b1b6dac0477a3dd1accb0c5f541a85fe9637ca9cba15926153ce1edacfe66f574cd4b691adbe0c90ed8563ccb401bc93288e9baa06c7b837f191f8de0a5c9b2bc0a5b730eabfe56f13d43afa142779d8e99b86abbd791e90476ec64759d30194b631c6e425053134c3c0792f9d122296"_hex;
        s = "9d64c3b9a4ba78889747aef7c8565eb075e5bd92a55f9d34d3df6a2d740cd863ff98a04be4866e9f906cc6d99270d208a3dc2e53201cac9f4f758eecbe8a44db0243a3e40400cac37856079f2fe02d54d9748754331d9935595c35b22cc6c45686ea964642ec4ca7e0a88e4a4c0a6166733e361c46a592469cad7009ca3170cf3fbe485b1c8726e23a6e35f9691d9bf4029d82756c64a4d31ad0b8ef57a0ba2d55419d7cfabbab1a23c8baa4bf043a444b127920250551467d7d528425dc7c903c2c824e6b9b65f543ad9d7055300f19500356100411271e15b939d496b4bd4cc3ba4b6aa2ce65f4825275404cb19512ae27cc986b0af6fddff35980c2cc0e96829ecbd9ee19944838e4c83b1eadb6f78669890f556781c4e97d8ede9664080e47b3adaf2f5e04bd42d46012aeace3078f9068d870fee02b088f9674fdc0ca0064e9f0f63205836d7a8771264c553c945eb7c87df2a13d8efd3cdc8409843e7a246089970abd43526f3cc9cf993d419a6beaaaf6830208686a1fde4733f078ac"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "ac6db1"_hex;
        m = "973606b2c7e5658a9d8f264b8f5a266d0992cfbd6e9d3ff95c31a69a32c4f0f1cf44a5759d090d5ccf089768e6497b047a9b9f8f3786b8f82681b18b2d65500ada2217005cb06852d249ed17c9d637a9ffa7a5fc6d66882f854e8461b9983ac63c3623fa0cc4bf9530bcf0ff3ee9a086211eaaad1927f8c70300e9c5db45f54d"_hex;
        s = "355644f5a26a4ffc638c44ab4d0b7359f37845235bfb994d28e63b114c0e0f97d2e29f448da8b12eb804792ccc686dd807f44211d6af410bdca1196df84016b3cdae180bbb59133aeac5928560ad2cf6be61392dc9e28d7ada11658cf4a873bd2626ca839e697c79a5c4bb3ed4c9b8f48f83f2800e1907376f2e8874c23f1dff8bbf3b3f98bed7895d486079a92557a553a71e18cfafdc155775f39a77455b432b0c2c4f09990d130060143e7310b9d9e1ae6f2b1b83b90b36c6581473f60c3c61a10e286557f84e5d04cc36e12cbce835234d2d773221313ad7287c9957d94a1cda8c1fccd3eec45dd84a5d075d6bf823123fcdc7d549286142ab514db6d998e377429494f07041387de3ab31b02ac1606e590572bd9003e5a62b90b95b00c0eca73c744ccf4eae44374e26ba6033dd2baede95e19cecc840a045bf995a3250ce7b08e0c3267de822616f93a4dd9e629eb38b479bd31071b48976cf73ce52c3734abd93249300dd5c40635842dd2a290276190737a123008a4f0be557ca6628"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "ac6db1"_hex;
        m = "170dcd5458adfbdccc757e0b5abc19278112f24b418b995d395b46410da3624c0a8b49fc0d914fe6a02101ef6765adbfbb5e24739434be92acca9f43e19639bddbb012fef028c7c0449d52a9350b88c2f6e5e52a79648c0c931e8ace5bda5b8bd3a3afc4ca1b6e520012f99f8c57b3167bcec0d8bac30cb1367e8f4a4118d0a0"_hex;
        s = "6a4db2e6c13ee8ec6174bf57ae5bb7555e66dc2e3b618f259d913b5b8b6c16b9760290c9c576b563316f510ad2461cd5086b6d9670551ec74b8a9d15ebd43ccdfdcd74cad660a3fe3f36992c86559cd8e9e4d3568924b1f7e55bc5d8df4cf53f240fb3b945a08d24f205d5a7081410ea3e8136ca282fc99e6be0b1fa2faa742c9d682d08a77b791bb0421241e6a82f84605dda359e4f8475cef346c9f6a54a085492fc4bbb30b1047c66f5fc529ecb6aa9ece561e5a3a62f9a19eca2badbfa32a2aa205713b16081519c2cde2f8e8261726fad49145dce0d9e24f6e085e44bd86f670a114ba98d54389f0ed683d062735cd495e6a8a6eef9fd70355b92b4cf6cf0c24e898b6d3f7fe51dcd1548a1adc67ba585e2d18809ea658d6ec4bb5e33e8501d11a266f5e0928ecb58547e72c27db8b07aae31eefef865bcf6a08485675d3037f432c157e5ee428d292bfc24c654d8fca7a60107dc18461251906521e1e9965fc80c7b5f582ac3dc3798a0a2937e76d7e7fd7122d3fd9083feeb9a44ad7c"_hex;
        r = true; // Result = P
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s, "Failed verifying valid RSA PKCS1.5 SHA256 signature" );

        e = "ac6db1"_hex;
        m = "b2f72cef31be4b7439191d9b342065e62513792826f950481486dd4289429b6e0ae86a05820c99e1ef0144845cfae05c0f6f144603c3ca50992387c38ab1f76120e2cdeba624cae61dc51a9f3010e76d6ab92936a77bbb34c8ffb4f9ab00f4b15badfda8834e050c292b49f398a9a39f9eb75f01f8684b7d0be10dedd576b9e8"_hex;
        s = "8ca52a9040ac49ec2415054ee86379f297832a2a33892c9dec09de778982fb1bbff68b3787ef43ad15f9aa0c518847ba1b3075613bf187a6fc8a7fd7f0b43a6a24086c1d6c5fcb1db18c93bc508e609396ba019fa43dd19f95194c47003d6092303be35477a3137aa2adaa51b22618db29fce98b5bf791ac70be7e238c558f0fb42a40bcfe0e9c07e178afe7a2db74fcb03693ed46719d54d69d5de43ad6a93b0a5b7da6e05ebf7c4b02da42c7ac1f8997da7c4de00c7747361bbef534461bebc23477e93a48558b3ade7d09dce6fa6a378e68e7204ab35283c58148df0cf9444e5f91ad31cd0474815895555cfd7f9cef9164b91db4f98816d194f85bad581f410a655273e5d14491793141f9d928cb30a322c513935dfd830dfc75030b8b2ba1f46b763ec303bef32b4dbeb01781bc1f2bf2ceba27750082661558cf3d42f03d50409b7db521299009753c25926e3e6502bb1763ab68dd5c19dc0265b16a2d438c3ed23b74e60ecff88708e5601a478986dd1b607a2db0fe049664d136517f"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        n = "8aa12846ecb9d8b954d2ca0fd3f60826c76d2a98ae615f38f5a662cb6158f17f29050dc6a1bc2f60f3a9db2da6c9b27b8cabe25cfc25d005ad60ce298f6da3415ee0a0a00cd2fbaf1eb67d4fffbe03b2570ab56c10dfee9f4da86c05920993c92c4ac33a246f5102113a258e17736897f981b8b29ae695802fa1bcf9b41a5f1053bd77400a153d1d6efdf4e4c14703a34380da2921deac003b4a7246568527d9e37d0da956766f155d3b9a38ddb747f2706a72268542f594c90e0d2f0ef755f4aa67aa6a25004548c73861c0333597337a944c42f762ca2b54821425477e4e0e2a9b1842ed3f16d68ed31318dc396071b90e1e514cff975d198a581723cc98cb784d18cf197a14dd7b9d5036bd7724b9301f514236bf7c8b290dc5bd93ebb6bb2d18d3fc4f4d480b8d1b62ffa3de1224607976a27d40f912e50b46b915f19556781b2ac88e16c14982a0718bdb4cec77127165bd7151f0181cf56efa1ea345fee075a7b36a02e74a6f3eb035b608cdd2ceda4d738876fbd7ffb009019581685f"_hex;
        e = "74ef0b"_hex;
        m = "1d15d87fe7045f2a6650659acf23faeedc28b1bbd64a54f8f3bed617e3438975a6a891f4a08f99e6ef72c52efce3e7a15018f5b3aaa6bb4f4e8dcd069f75c06cf03799bf989f86ca4471cc0992a9010edb077b234fcb083148bedfe1d871d700a4c9d728f6bb8e9d0d556475b8feb0fc23fe2b56f041a5668957f6efb5c038f9"_hex;
        s = "1f1563cbb8650b8a7ff7f71aba6c06ea20643e4620f29e8d1aeb4a1be6f665ff9779ca9303437aad3264aeb0f2b250af32054585edeb44b0a913175e6006d31b43eeb9c97bbd679e5434e8f645b6e096320a5906a64264abdb9cdeefabd5ff61ee3f851484ec6bb0c7957d6db38942be1b3412aeaa7b0700028fac765cc4f03bd7157122420f1acd4828ea01cd32e0cacc55f43fd9bf58ac71961031f72024832191598ae69dc96b458a237cae0e3a81784a98a1b012530936529efe73d073eaf974f8e1680706581e0accb3a189d80dc71b051474e50cd9d8eaaf9e7be4108be1e7d8e6a89709c50c2d85034f0e158b208a205fc4b30922d0e19ca58e15e46384ec15650ff56b6eaef908b44c4f9d71250fd050ce96acc204d68c09493596ab2bf3052792226d60b684e516e92fa0b1585dffbc309fac46457c07a901e901dd659e4fbe4ec0b327f88b8b8bc689c3f678aac3519ec1f7392936a726b7fe4be534b27bac5a35a55e18fdeb08857850940476c14fa12102014872b81bc5dcf292"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "74ef0b"_hex;
        m = "50930141564ac38dfef23056b5cfd10efcf3bb8823fa6f5254f8ff45d4b0725a86076ac0b1b8042b0248006ed53d224cb08bd78b104f1c4b69bf9c96686118387b7c0cd193cd9028297a7cc27f4ccfb4281852b5ca7e787723d689384a68ff9437db319d86f12e2d7871ec7b3b64a2ed6b83722dd8f14b7f8a260e52022bef14"_hex;
        s = "65862ec1d10c408e4278ee1421e773f49ad426e368a48136d6f77d5a6de96ef4643ef3b8f7b451f9ef9ab4d8590752dd7adf1d78ce23411f3586564b67172ef718e8824d357b37f105dd0e38c0578df14220dbd83588c56c4cc658b5d4b07337ba3e40b40aa6d877aeb3cb95256d25e55b702bdb23026bcf05387d58ce020d359348536f9f108d111bf69c3823aca8655bd73a64789d258bc90b5006ad01c0640118e17aacedbc0545c543df8e05f254fb7d8846703723fadbd4179d4a1a5a7c371e980309d33b2d79061f741aae529d4e84c686a4077d3ffc66a8b18fab2f72ed06a3372efee4507425610d317c74d5566f4829b079012e2e066bacde53e43dd702fae3861eaf2721e3fc5818de552b5a9d084b5f03a451527fce2d3a608028163befb91ccecdcaaaf5cc357bfb698f0860350136b71b4b087b50e2d97a9a6765a6077f1b26e168b5d60b7a91330c3e1769adc479ffd866351eea4cae92609c0431511b91b6683d0d8d4d2a72be8622c7dd969d5977127ca5a6c3d0ef7ff77a"_hex;
        r = true; // Result = P
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s, "Failed verifying valid RSA PKCS1.5 SHA256 signature" );

        e = "f1d0f1"_hex;
        m = "b1fe0c7145b1e35a8062ed24ab82e862a0d695a53a1cc7430af1b9574bf2a40918229110dd8c6c750c295b9911034e79879bd631ac883abf1262c80a98de6923993a78ca63dcd434eb36340bbfecbbb73b39cddc008f2023a27d163ea1d64a269b1068a7bfea431f855121839c8559a2247821ae1e77a1f8210b4cfb4e226f9c"_hex;
        s = "43333cc1b7da9710ad7f58a595078672be48dbedafab37dda0e1328e2f2b8b91dc88d2c33e0d8e06fdfa3dbc43e24d827f3ed31a994bf662225e1f0827a205cd638c16f38d664752d73db2c84f26d12a955e237f7a4d171a14d720b43dda3fa728d69ee0ed95869fc231d8f6fffe93b1acb81692ab9ff0f926073280a3bdd4472cba3b84541f1f9cd4508bf780e96c80b4a705c9893639f127969343a1ff9aab2b98d154c7f929fc55a5fe9485d1d9ca411131e5c0ff3fbaef353d49a9f13583cf1ebeea6209c123df32abcb311edc94c04e5eb3e1389e5011499e7d0d5bf66bb69ba7a06586d414b1d7cedd0106259406235fee1cf0b2bb2ce679f247741baecccff27c6e2a3a514d7aaebed281cb6381e7fa8d8a092ef1051b5418fd9886747c9194feab56eb975fe193076b474c2056d20a818a5b4ea56648ab5e7d4ddfdca1238d95da14dbb51e0a72b6df8d4e4d708a18e1828619c999525772400a9ca91c20229b1a979d30fa7bf7e33129abcc8d91f61ff0b8f2042345c27a928b7865"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "74ef0b"_hex;
        m = "89574c2f705f32cafde26824389468218712eae98268588f02d683f17ad494df8b53457fd24651ef0561282d3e20e834960c8968f63a57342a14a6f2375bc10bef6d235fc2c4eae7d7c088985ca6bc8b1ae8c15c4ca7c5d0b1769cbae061b61fdc2e4e98e8e2e5f89c87ef2f392dcc6e3a2ff98c2bb788a9be84cd111ceb5b62"_hex;
        s = "45c1da7fa6d790ac28f54716f23b2d594a637c5f6785e37fec8350e5d5334edceb66c263197702e5e5d543a2a9a6893cec3608512503ca26831d8847c2563c326bbdf3aa5edf7a583d8252e2cf35bb16cf30a0736ccdddd41af4b54729c843b9c675ab33d3ba1e1f7f63d2aa2ec94da2a9fe4eab9036b0561d5ddeb6d3dfecd1e243381de0eed5d41b8fd6023826d3bf4ffece8570e800c1689a57c2987a0f5629dac772c5f40b475ac61524c0308dd7de872d2f2d68c6017992ee060c607826db6f263f3276f330b7d267defe6eb91f9e9ca63e552531869f0b36784813991da6aa930736858146a42eac2b17c3ed2fac55ae3e0c6370b5302e693f84615e4174576150c6454a5c5f7a4f72d03630e899363db71eeb8e4e919ab6d15e87306c626dbcc18bfe62bfb1878a5105cef0f5b4f06cc4b6d7fc12f29e687ea9d0e16b7ca009356a2cda1f7b48b22e43883582cc770803f6c75892174168ac6954c76a475f0bdda4dce703e5d7737f7019a43ac72447b524a6132dde51f925fcbb9485"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "74ef0b"_hex;
        m = "a8d283d3e616fcdabe06076c3368e022884108cf569bf363db860010955dafab0f4a0f54fc0c755982f87358d83e08a4136e15ea3d3b1015a87efc6e817e9908a86ed85bbf37912f827878bc56cb4e0f244b54af67530581848804e95b1954321b45c7305a1eb923658dfddfd497182a62dead66fc6b397018aa01c748b648f1"_hex;
        s = "5961403c27cac4677ccde42cb807477e004b7cc795f8e14049e78326769803f852175ad36d6cc08232c168a34e33eeadb7aaee642b6a75928ad303fb4140eebbfc2fdff5a990f8bea12311529cc4575594a56f6d362a6cf8623cf6580eae79525e502c7be1ae71699e2b7916cde5ab5149840ce8db96e839d0d507bcc3d6184ec68a99c30a1b562959d7873027aa491a9dee9094249e7e3e1913f263e05b6d892a8787686baa7ecb9a88e3bdb52a7e45fdf49bb73588173c722c5503bb5864917410da43ff55e85e4df1af4bdd3b913ee5ef8b9f0293ef36641a775dd4f70df95f157569899df3b7f2cf54a5e34575ff9f6ef5b93d00699586a247c2b42ddccffa5c88294b7bfb686970e0fb9a1e7a823a8b16ffa9b5e45726dd3bb015c88307062aab622fcdac7ed30b7c773793d3f7ce326d30535f4bc289918aace1feaa02c620be6cdcde24d694e7936c58c83f9e4bc3dcafbc542afa4daa7be014099173708452817dc1493d3306053e97fd1c258b062a982a5333925472eb004d82d8e4"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "74ef0b"_hex;
        m = "b2a9f33308f84f8718e860ee4e439ba1541a985f355c5dabc3a8df343660c69515ff713e5aac3ab2d10ffbf4c163d13bcecc1fed1eebd6cbbbb0f46938704be2983884c96b6063633a634d1325ee0715cb36c06f6a8f5225473bc5ad517f14a201fc34bd843d53001c8d5e34c40bc596130082ce626f582031ee58e6c7b5aa3e"_hex;
        s = "6f443dabd187abfeb167c7a76954251cb017b40dcd3c0de81909993fbdd6c99f64613e73aecc29eeb29fc9aab9ec54b55bc3539e0d34095248b5536b35f1a079a4f09ca2e83f51b07ef005a7e0a915be137e1d94ff2b26eda29a337b5b8d8652cb9f98703648a4b0d8c759ba48c1c37b2b76c3bbe116574c1f6265cc19703ce489186e3951e97e0d26230a82cd0b2a24def62b8af8e4962cf4e1a693d0d0bebd6fe45966b3a4e890e0a6f535919661beb109eb6d11e73ee2b97a3dd20074711bd4b817f442866d11c3fbf62255e05e466b36b8ffd57c6abe5592d72061d96435dedc32a822aa342b159ab21a993703b5ee7bd6d55508800b67667188810e062be554244db902947bd2ebc7f9e6c899f6ca1d3ba3a5c2edca8bafca8a5b54426b04a5a16a3c752d18647b578904f60a5dac531c95b0bfc37b7aeddd3c3564d0581f1088e85ed85ca366ef94eeb8f8d06b060f73f20778ae83bb884527fe9bc1a04d6dca59fefdfb9e14d68f97d9fb5fb1045c9a229d3015a4867efe88791554f8"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        n = "8c4b17ab9a0da366f67416075ce284ff69a2c1112a8b7d821f66e8bc5386cd1abfe499fb9a09523f1095729f61433cc17fed78789cde81145ba02d22ddb560332ec795ea6a764b9fb380f44ac63d64225772aa4503df2fdd20e7c1d17115d3c56176f49432b2930d417b84f997ed4e50cd557e2786e0275be8025f6f039a7a3b8ed421b4c224527c01c1a1bef6becda193eac7f484ab0a24da31d4bc8bb6f2d4a5f3817a246bd5a9c81dfbf55e8c5b18a8a63bebdcd245726ba5b6ed4f8981ab83933c00714064985d69a17ed017e3cfd7fd5d2c6e932a2e021d226013126e6272231ce8bf626121710cd19d0ff21227e4c4255be507809aeb0aa548f42749bae8e1a3e3b312d08f0226c5245c45b5d96eb8eaecd1b8a1dd3f9f908191325a02cb4ca57b25155447584749e2db23360233d9068195daebb7ca943311b58dedc6c809a5981ff1b66a803a4135fbddf1f4f2478559f9d2ba17d2da77b0f0b6b08662eb50495a16c301759cbf7281f4fa985800c14386e0db6df0422bbda9a26441"_hex;
        e = "e5a4b3"_hex;
        m = "897bd083c89256d56a247c12e265f3390962eace1cef2f7504e197bfdb7ea144ab3256f2798473a48247caf6c415e658c0f9ee627f6ccb68d3838d4ddf660b9cd904cad40f05210428009a98adef9a73c8e0453e4bed9cfff36de8edef6c5c839c59f6d393ffa61de5b7b2a0a5db59b0a77db7098859e863ee0970461178da20"_hex;
        s = "7a172ef111b0f2f9ec43bad8f6e8fa11e19222ed9575571716e55fe46b43aacee433447632849e0f486744054e70bdd98863f5f015b94ddd1571e64f6b9a26302e151d4865423791d596063bfad7e3b5c5494f4a3c5ed994c53b6d915824a1f1e8e3639f8873f9095a7842d88817a93bc2651e6ba94acce93830735654fcb5a4a01cccc090ede15ff5ed745a92d92d8186a746a693a94db4fae34db26c6ad0b4904c63001600947ee994e24da490a3de240e500b31b8be8b1b415599aa684c77116f12e3cb218cf388424e3276b1a3622f1c4115125f5af47d581b78b609a067ef5f33549fadbdadd098dd2c337897f113c8eca9a20f3da69aee2fe4a89bd3ff73eb4e8da271065a9013935731addb3480f52d07fb3a91261d8a030ee2cd9e0ab342b3bd62db62e359475ee9a36971ba37f5c3ae1f1939c276980140961e9542be9e0a4739fce668549fb606ae18774bbe62b20148dee0379f0f38fe982b25bae164785d3410c337b2f11ea74558d79991760847109dc0c77272a55afb0d3f58"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "e5a4b3"_hex;
        m = "77ba90225f3ba1722312f52b1a07c3f659aee2a085e939c3e5ae77a3bb0a0456d56637285f0ac93dfbdf89781479529c6e543ab1025e0daa0ab6fa4458b48b31eb29db76c4e80312f685d5e0fd5ccdbe50d544ef3ae7e7bee5db6864b853732ce28ae4d537dd37383c8b3f2b7db91ba427b96722d28baf489fa429cb83efa38f"_hex;
        s = "1f442887263f403f6ff9b20fd2780937596e99e3c9e640def7de2006f14026de1e140e0cd5d45d7fcb1f42a9127a661c87cbaa4f9b600d8ad7fde5beed5c125294ad7b211d550bc35429c71f84a837eca906a580aaf3e301b46deb59ebfa4b66323f6e136d178f7ecd8440d891eeed5c91ed785ffefcc725f2792868e296a8eb03c5683ce791b554636a787d579e3db81177b45aee1ac6bbd90d84144a706196d557b48d7fa8b551c3bf638ce93a6425eac03232256f4cca758ab2c427d996702b522eca24b0781f33aa2b61e1256fdb94b166f98cacea3d5da205f818d19b432d50309d8265eef151b0f40fceba927fd6b5ec9d1c2ba54eb9af22aa354299ffad07da5071a1fb4314c69399a5aa16c3b4ff3b61937debf6e55b5f44e91855ff0a64ab59f549c3b4dcbad5c4306b08be4b1be99d000ea52665e9bd1983fbfaecb15ba18adb3e88bb9429d6d1aa85f7f6304c253692ea0ae579123703f9d89f69669fdd4c12607d8c1b7a28f814e75a45122956c21cae47bba9e4ec1afb707e5f"_hex;
        r = true; // Result = P
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s, "Failed verifying valid RSA PKCS1.5 SHA256 signature" );

        e = "c15efd"_hex;
        m = "34a83157520e0413bc2ec4b48034fe5cc3fd2f69fb7992f95e5437ad99d555aec606e1ee98155fb1d9faf94b175ace2b9aab8c18999a41bbada96e5e851d5ef3dc17b558a8014cd9942b3cf7b1b6396768b2225eb483d50c8e894866a800d6295d24d61ce8997295d50bb73eb612e819175818c2b4fdf7f5e93aed4f69456559"_hex;
        s = "7a1699fcecfd4d337bcc6f4904d2356fff44aa24fd4a0324945d4a4dd9a9a552c59239dc9268783067477dade944adf592495a3b1e5a6eea7f58762ec4d5b0f3515f3b1eaab1273476cb0cc3080fa8c7d2f2695f4417a6dc538b8b2c58bfb248b7c41485aeb668a0a39ffa324f25074c75c0ae1c70496a4a37c9332fd73ced1d2fe561ae120c6c19d1e526c211ce8869ce236d06a9dab8f9ef453f8854cb4451033960a62fe279830667845edd5883734e730e50e7bae3bbcc619e5c4211ebf741ad2526bf0226440b7d076faa02a30f2c79132443de9fe9e6bfc12c65d1ee703ea274c06ffd5cf945413cfe13d1ec63d48ea477ba8c60a7aacc078b988cdb58691911975f26e1b33c2c0ff3e5026d9b1d7a6293eb330ad5513efd19937193b796c40114dd1ff32a2875963020f26177ca1b6a7d0c6a40a6c0be44b03555c0f4598f91600a336c73099fab278271c46d96f16d6882c00d5b3ba59f2a0bcb98f39b152c55eaee62a4eba026234f15963d7e7395de927e94893a8a175c65f0dd43"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "e5a4b3"_hex;
        m = "72e970c5fbeccfb254bb1313e33470e3074dd8d3fc60093fffc7c960b2a970c3c113a8fac64b71916a616844cd06486e29a1b1c5b2a02845c00c606a2f61b7a2069c040258959038688f62c1100ec05c64e9f2be929f49870dee6075eaa2a2d78aac0c457973348f966f8bf374f3df93014a2426650673ed2d9553e8a915384b"_hex;
        s = "6ce37157a92a7eda47c16b5b2d961c564ef7df9d5886043c07abbd1e74ec7f549c78b07e2140207e6b93e89ae69a74a5a76184e00ec03f1dd36c0699535e0bedb4f28634b194fcebe13d2c4955e01e4ef459244a7497fd647d5e6dd5f7ec156929d0e2f1e146d3397d3636726bbea13b38d7d38d4a5e4ebe68df7ff86c62c3802e18250a2cab3d200363c577895a33dc69c18d15309e7117ebf47b3b98c893785c99dd0077982ee084b4ac08913de46415e5abdbd223aca6ac5574ff4a61f5fd7631b776113f12044e5e53960a5af3867c8366e3367a20de73e6c4e0f7b9075a1a79374aee0232d06280c53bc6a148026e1686059d652d96c99ac41f909e278b3c408568adfe35cc55800caa58d03ce9f1cf533018ec4fcb5d66a50758229716c2abebe4b3e3c6ac778fc008db8985e5032d7825fa333fa4d7468504cd0785000f92833d5cdd61880bf40f803ac298343d75e18c003a8471e06449406bf1bafd988e162b0b8c62eee5795d957f1fe5d7abc6e7c8b3b43759f212d01def9151dc"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "e5a4b3"_hex;
        m = "6147121ced1b5f1d73306e4a22c31669b76c20764fa4b4467d86126a9ad283565c378ec3aad26e51aff2c4712e1e8a821559483a54a48a48efc5913752474996e6c27b56e15c44736290c6d7bd2e1d7b13a394cf277b195c6c24efa763f5a359236e419e39c2c7cbb392da4378fcb89bdbd46efc6f314bc91c2c948272e479e9"_hex;
        s = "8b5320215e2133754a182f38444a68fe9f3cfdbb7ea9d8e55d006789fb1d75c0fbe5e94201b15c97613a35c3ab54d61dcc62b978a8fab0ae3183fb7463814ec498eb0f4b0f5403044f33368afcf692b1b3ee3ef0ec1492c5c2ec370d75163b777705a0675252908bff8010e819bbde67b86b33a35e1fc43cb8da167691b6d69ecc19ae094a5461cadb0e977ea6b7ef6f3f639e4571a073d6033cf464e5eb17323447ac079e4e69caa7966d3083ecf616394fa25d2e30ef4e5b7e558c8c46802c2e35db02b7884b53b89f041037bf10ff30f291003323112dcc6b8eeebde3bf97e373305eab433061e3a634df865642743908ef822df62cedde8f4af403e7a924e22e667734e91a29d4b6c8f1c12da7023a1b22e6a3dd33e878efbab31220f4f2c923c88f1bb0d7b7497a9c687fbf59f9eb4625e6f92d7285bca5db93ae63213e3fe1333801fc3eca1d3a1ffa75319752a5aaac461d7a799659ad31569230266c1a62e787c25fa635b0d3aa248d047d9cee43fb12342a4c066dc971b893a7dbcf"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })

        e = "e5a4b3"_hex;
        m = "e9ba77e32581fb11b3d44a885ce8184207a00b5835016418cfe6e25921f4e30b26d1cd120691ac55dd711d11bec86a74f83af667972fdcab2e83d327d48055806d0900eb2b173c3f546a1e4f45788c76b7aaa27341c755771eb0567d314f39da46cad7159bfcf1f89f2516e7f9e0c671cc56d72539b218a726d535033e4ada40"_hex;
        s = "17c273523709d84746ae546c8f58086a5ab385aade0707b5b39adbeb507670453a56bd356a9b549fb0112eb3be73466294c0180a9061b04128a001f62025867277e28508fd1c94109061184f6acac575737ec4f93c58ee452089e6714c4dd9f23833278dc66332a914ac8e1b0ec33472061bab9c29cd8d7a0c1778c71fb973c851b6c9bbb7b7dfd24a16f146eef248d1aa81e4f62cafce2ea146314b2a8d5711de6625011ee7ffe7ac49b03a5b7e2d842e9b35969a934c75d16b6cb890f8d4ebeb6f74a08059e70e90ee39816cab34c4702ccd4e14718a8ab5c981f9c8f7cb3e91bf066ba387824c1b27e33b27a06d9eb3ff3fcace0b285f51cf83b117005bcc12da946b5a36e9308ac98e9103becc8ec5dbb048df722e5c8e6cbeaad8f2e27af33648c9ce5d7940013146f5d3cb8c30849ea75b209c36b745dc3179617933e22dc25af5169f784d6128af2c8694b5caf19fbc0585ca1780181150e8f8bbd8d12ea8b0d41f86b1b3b27771b3f36d3cf5ac6a2702b8711d52edc1cc96ce071eab"_hex;
        r = false; // Result = F
        d = eosio::sha256( (const char*)m.data(), m.size() );
        REQUIRE_EQUAL( r, verify_rsa_sha256( rsa_public_key_view(n, e), d, s ));
        REQUIRE_ASSERT( "RSA PKCS1.5 SHA256 signature verification failed", [&]() {
            assert_rsa_sha256_signature( rsa_public_key_view(n, e), d, s,
                "RSA PKCS1.5 SHA256 signature verification failed"
            );
        })
    EOSIO_TEST_END

    EOSIO_TEST_BEGIN( rsa_pkcs_1_5_test )
        EOSIO_TEST( rsa_pkcs_1_5_sha256_test )
    EOSIO_TEST_END
}