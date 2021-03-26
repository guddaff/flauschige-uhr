{ pkgs ? import <nixpkgs> { } }:

with pkgs;

stdenv.mkDerivation {
  name = "flauschige-uhr";
  src = ./.;
  postPatch = "substituteInPlace Makefile --replace /usr $out";
  preInstall = "mkdir -p $out/bin";
}
