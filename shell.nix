{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  nativeBuildInputs = with pkgs; [ autoreconfHook pkg-config gdb ];

  buildInputs = with pkgs; [ libbsd ];
}
