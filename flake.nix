{
  description = "A cryptographically secure lottery number generator";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
      in
      {
        packages.default = pkgs.stdenv.mkDerivation {
          pname = "LotteryGenerator";
          version = "0.1.0";
          src = ./.;

          nativeBuildInputs = [ pkgs.cmake ];
          buildInputs = [ pkgs.libsodium ];

          installPhase = ''
            runHook preInstall
            mkdir -p $out/bin
            cp EuroJackpot 6aus49 EuroMillion $out/bin/
            runHook postInstall
          '';
        };

        devShells.default = pkgs.mkShell {
          packages = [
            pkgs.cmake
            pkgs.gnumake
            pkgs.libsodium
          ];
        };
      }
    );
}
