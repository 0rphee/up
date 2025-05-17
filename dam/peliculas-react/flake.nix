{
  inputs = {
    devshell.url = "github:numtide/devshell";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs =
    {
      self,
      flake-utils,
      devshell,
      nixpkgs,
      ...
    }@inputs:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = import nixpkgs {
          inherit system;
          overlays = [
            devshell.overlays.default
          ];
        };
      in
      {
        devShells.default = pkgs.devshell.mkShell {
          devshell.name = "reactnative-1";
          commands = [
            { package = "nodejs_23"; } # node & npm
          ];
        };
      }
    );
}
