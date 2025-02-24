//
//  Usuario.swift
//  dam-ex-p1
//
//  Created by roger on 21/02/25.
//

import SwiftUI

struct Usuario: View {
    @Binding var info: Info
    @Binding var showLogin: Bool
    var body: some View {
        NavigationView {
            VStack(spacing: 20) {
                Image("img5").resizable().scaledToFit().frame(
                    width: 100, height: 110
                ).clipShape(.circle)

                Text(info.user).bold().font(.title)

                Button(action: {
                    // todo reset app state
                    showLogin = true
                    info.user = ""
                    info.password = ""
                }) {
                    Text("Cerrar Sesión").font(.headline).foregroundStyle(.red)
                }
            }
        }.navigationTitle("Usuario")
    }
}

#Preview {
    // Usuario(user: "admin")
}
