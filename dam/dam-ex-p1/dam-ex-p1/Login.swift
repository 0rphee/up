//
//  Login.swift
//  dam-ex-p1
//
//  Created by roger on 21/02/25.
//

import SwiftUI

let usuarios: [String: String] = [
    "admin": "1234",
    "swiftdev": "apple2024",
    "testuser": "test123",
]


struct Info {
    var password: String
    var user: String
}

struct Login: View {
    @State var info: Info = Info(password: "", user: "")
    @State private var showLogin = true
    @State private var showErr = false
    
    @Environment(\.presentationMode) var back: Binding<PresentationMode>

    var body: some View {
        VStack {
            if !showLogin {
                Tabs(info: $info, showLogin: $showLogin)
            } else {
                login(info: $info, showErr: $showErr)
                Button(action: {
                    if let pass = usuarios[info.user] {
                        if pass == info.password {
                            showLogin = false
                            showErr = false
                        } else {
                            showLogin = true
                            showErr = true
                        }
                    } else {
                        showLogin = true
                        showErr = true
                    }
                }) {
                    Text("Login")
                }
            }
        }
        .padding()
    }
}

struct login: View {
    @Binding var info: Info
    @Binding var showErr: Bool
    var body: some View {
        VStack {
            if showErr {
                Text("Usuario y/o contraseña incorrectos").foregroundStyle(.red)
            }
            TextField("Usuario", text: $info.user)
                .textFieldStyle(RoundedBorderTextFieldStyle())
            SecureField("Password", text: $info.password)
                .textFieldStyle(RoundedBorderTextFieldStyle())
        }
    }
}

#Preview {
    Login()
}
