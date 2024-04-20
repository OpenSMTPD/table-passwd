{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  nativeBuildInputs = with pkgs; [ autoreconfHook pkg-config gdb mandoc ];

  buildInputs = with pkgs; [ libbsd ];
}
